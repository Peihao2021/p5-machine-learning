#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cassert>
#include <cmath>
#include "csvstream.hpp"
#include <string.h>
#include <sstream>



using namespace std;

class Classifier{
public:
    Classifier(bool debugMode) : debug(debugMode), totalPosts(0) {}

    void trainer(string training_file) {
        // open csvin
        csvstream csvin(training_file);

        map<string, string> row;

        if(debug){
            cout << "training data:" << endl;
        }

        while(csvin >> row) {
            totalPosts++;

            // cout << "Tag: " << row["tag"] << endl;
            // cout << "Content: " << row["content"] << endl;

            if (debug) {
                cout << "  label = " << row["tag"];
                cout << ", content = " << row["content"] << endl;
            }

            countUniqueWords(row["content"]);
            countPostWithWord(row["content"]);
            countPostWithLabel(row["tag"]);
            countPostWithLabelandWord(row["tag"], row["content"]);
        }

        // extra blank line;
        cout << endl;
    }

    set<string> unique_words(const string &str) const {
        istringstream source(str);
        set<string> words;
        string word;
        while (source >> word) {
            words.insert(word);
        }
        return words;
    }   
    
    void countUniqueWords(const string &content) {
        set<string> filtered_line = unique_words(content);
        for (auto &words : filtered_line) {
            unique_word.insert(words);
        }
        // for (auto it = unique_word.begin(); it != unique_word.end(); ++it) {
        //     cout << *it << " " << endl;;
        // }
    }
    
    void countPostWithWord(const string &content){
        set<string> filtered_line = unique_words(content);
        for (auto &word : unique_word) {
            if (filtered_line.find(word) != filtered_line.end()) {
                posts_words_num[word] += 1;
            }
        }
    }

    void countPostWithLabel(const string &tag){
        posts_label_num[tag] += 1;
    }

    void countPostWithLabelandWord(const string &tag, const string &content){
        set<string> filtered_line = unique_words(content);
        for (auto &word : filtered_line) {
            post_label_and_words_num[{tag, word}] += 1;
        }
    }

    pair<string, double> probability(const string &content) {
        set<string> content = unique_words(content);
        double max_prob = -INFINITY;
        string max_tag;
        for (auto &it : posts_label_num){
            double prob = 0;
            string tag = it.first;
            prob += log(posts_label_num.at(tag) / totalPosts);
            
            for (auto &word : content) {
                if (!posts_words_num.count(word)) {
                    prob += log(1.0 / totalPosts);
                }
                else if (!post_label_and_words_num.count({tag, word})) {
                    prob += log(1.0 * posts_words_num.at(word) / totalPosts);
                }
                else {
                    prob += 
                    log(1.0 * post_label_and_words_num.at({tag, word}) 
                    / 
                    posts_label_num.at(tag));
                }
            }
            
            if (prob > max_prob) {
                max_prob = prob;
                max_tag = tag;
            }
            
        }

        return {max_tag, max_prob};
        
    }

    void printTrainingPosts() {
        cout << "trained on ";
        cout << totalPosts;
        cout << " examples" << endl;
    }

    void debugger(int mode) {
        
        // mode 1 vocabular debugger
        if (mode == 1) {
            cout << "vocabulary size = ";
            cout << unique_word.size() << endl;
        }
        else if (mode == 2) {
            cout << "classes:" << endl;
            for (auto &[word, integer]: posts_label_num) {
                cout << "  " << word << ", ";
                cout << integer << " examples, log-prior = ";
                cout << log(1.0 * integer / totalPosts) << endl;
            }
        }
        else if (mode == 3) {
            cout << "classifier parameters:" << endl;
            for (auto &[words, integer] : post_label_and_words_num) {
                cout << "  " << words.first << ":" << words.second;
                cout << ", count = " << integer << ", log-likelihood = ";
                if (integer == 0 && unique_word.find(words.second) != unique_word.end()) {
                    cout << log(1.0 * posts_words_num[words.second] / totalPosts) << endl;
                }
                else if (integer == 0 && unique_word.find(words.second) == unique_word.end()) {
                    cout << log(1.0 / totalPosts) << endl;
                }
                else {
                    cout << log(1.0 * integer / posts_label_num[words.first]) << endl;
                }
            }
        }
    }

    void runner(const string &test_file) {
        cout << "test data:" << endl;

        csvstream csvin(test_file);
        map<string, string> row;

        int correct_num = 0;
        int total_num = 0;

        while(csvin >> row) {
            if (row["tag"] == probability(row["content"]).first) {
                correct_num++;
            }
            total_num++;
            cout << "\tcorrect = " << row["tag"] << ", predicted = " 
                 << probability(row["content"]).first 
                 << ", log-probability score = " 
                 << probability(row["content"]).second << endl
                 << "\tcontent = " << row["content"] << endl << endl;
        }
        
        cout << "performance: " << correct_num << " / " << total_num
             << " posts predicted correctly" << endl;

    }


private:
    bool debug = false;
    int totalPosts;
    set<string> unique_word; // use set size function to track unique word count
    map<string, int> posts_label_num;
    map<string, int> posts_words_num;
    map<pair<string, string>, int> post_label_and_words_num;
};


int main(int argc, char* argv[]) {
    cout.precision(3);

    // check command line arguments
    if (argc != 3 && argc != 4) {
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
        return 1;
    }
    else if (argc == 4 && strcmp(argv[3], "--debug")) {
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
        return 1;
    }

    bool debugMode = false;
    if (argc == 4) {
        debugMode = true;
    }

    // initalize classifier
    Classifier model(debugMode);

    // naming files
    string training_file = argv[1];
    string test_file = argv[2];

    // check training_file properly
    try {csvstream csvin(training_file);}
    catch(const csvstream_exception &e) {
        cout << "Error opening file: " << training_file << endl;
        return 1;
    }

    // check training_file open properly
    try {csvstream csvin(test_file);}
    catch(const csvstream_exception &e) {
        cout << "Error opening file: " << test_file << endl;
        return 1;
    }
    
    // train classifier
    model.trainer(training_file);

    // print number of training posts
    model.printTrainingPosts();

    // debugger calls
    if (debugMode) {
        model.debugger(1); // vocabular debugger
    }

    cout << endl;

    if (debugMode) {
        model.debugger(2); // label debugger
    }

    cout << endl;

    if (debugMode) {
        model.debugger(3); // label and word debugger
        cout << endl;
    }

    // predict labels
    model.runner(test_file);

}