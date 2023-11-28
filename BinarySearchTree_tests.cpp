#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"


TEST(test_empty) {

    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.empty());
}

TEST(test_size){

    BinarySearchTree<int> bst;
    ASSERT_EQUAL(bst.size(), 0);

    bst.insert(5);
    ASSERT_EQUAL(bst.size(), 1);

    bst.insert(3);
    ASSERT_EQUAL(bst.size(), 2);

    bst.insert(7);
    ASSERT_EQUAL(bst.size(), 3);

    bst.insert(4);
    ASSERT_EQUAL(bst.size(), 4);
}

TEST(test_height_full){

    BinarySearchTree<int> bst;
    ASSERT_EQUAL(bst.height(), 0);

    bst.insert(100);
    ASSERT_EQUAL(bst.height(), 1);

    bst.insert(50);
    ASSERT_EQUAL(bst.height(), 2);

    bst.insert(150);
    ASSERT_EQUAL(bst.height(), 2);

    bst.insert(30);
    ASSERT_EQUAL(bst.height(), 3);

    bst.insert(70);
    ASSERT_EQUAL(bst.height(), 3);

    bst.insert(120);
    ASSERT_EQUAL(bst.height(), 3);

    bst.insert(160);
    ASSERT_EQUAL(bst.height(), 3);

    bst.insert(110);
    ASSERT_EQUAL(bst.height(), 4);
//      100
//  50       150
//30  70  120   160
//       110
}

TEST(test_height_stick_tree){

    BinarySearchTree<int> bst;
    ASSERT_EQUAL(bst.height(), 0);

    bst.insert(1);
    ASSERT_EQUAL(bst.height(), 1);

    bst.insert(2);
    ASSERT_EQUAL(bst.height(), 2);

    bst.insert(3);
    ASSERT_EQUAL(bst.height(), 3);

    bst.insert(4);
    ASSERT_EQUAL(bst.height(), 4);


// 1
//  2
//   3
//    4
}

TEST(test_copy_empty_and_not_empty){

    BinarySearchTree<int> bst;
    BinarySearchTree<int> copy_bst_1 = bst;

    ASSERT_EQUAL(copy_bst_1.height(), 0)
    ASSERT_EQUAL(copy_bst_1.size(), 0);
    ASSERT_TRUE(copy_bst_1.empty());

    bst.insert(0);
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);

    BinarySearchTree<int> copy_bst_2 = bst;

    ASSERT_EQUAL(*copy_bst_2.begin(), 0);
    ASSERT_EQUAL(copy_bst_2.height(), 5);
    ASSERT_EQUAL(copy_bst_2.size(), 5);
    ASSERT_EQUAL(*copy_bst_2.min_element(), 0);
    ASSERT_EQUAL(*copy_bst_2.max_element(), 4);
}

TEST(test_begin_1){

    BinarySearchTree<int> bst;

    bst.insert(7);
    bst.insert(12);
    bst.insert(20);
    bst.insert(3);
    bst.insert(1);
    bst.insert(2);
    bst.insert(100);
    //       7
    //    3    12
    //  1        20
    //     2       100
    ASSERT_EQUAL(*bst.begin(), 1);
}

TEST(test_begin_2){
    ////////////////
    BinarySearchTree<int> bst;
    bst.insert(7);
    bst.insert(12);
    bst.insert(20);
    bst.insert(3);
    bst.insert(4);
    bst.insert(0);
    bst.insert(100);
    //       7
    //    3    12
    //  0   4     20
    //               100
    ASSERT_EQUAL(*bst.begin(), 0);
}

TEST(test_end){

    BinarySearchTree<int> bst;

    bst.insert(7);
    bst.insert(12);
    bst.insert(20);
    bst.insert(3);
    bst.insert(1);
    bst.insert(2);
    bst.insert(0);
    bst.insert(18);
    //       7
    //    3    12
    //  1        20
    //0    2   18

    ASSERT_EQUAL(++bst.find(18), bst.find(20));
    ASSERT_EQUAL(++bst.find(20), bst.end());
    ASSERT_EQUAL(++bst.find(1), bst.find(2));
    ASSERT_EQUAL(++bst.find(2), bst.find(3));
}

TEST(test_min_element_1){

    BinarySearchTree<int> bst;

    ASSERT_EQUAL(bst.min_element(), bst.end());

    bst.insert(7);
    bst.insert(12);
    bst.insert(20);
    bst.insert(3);
    bst.insert(1);
    bst.insert(2);
    bst.insert(100);
    //       7
    //    3    12
    //  1        20
    //     2       100

    ASSERT_EQUAL(*bst.min_element(), 1);
}

TEST(test_min_element_2){

    BinarySearchTree<int> bst;

    ASSERT_EQUAL(bst.min_element(), bst.end());

    bst.insert(7);
    bst.insert(12);
    bst.insert(20);
    bst.insert(100);
    //       7
    //         12
    //           20
    //             100

    ASSERT_EQUAL(*bst.min_element(), 7);
}

TEST(test_min_element_3){

    BinarySearchTree<int> bst;

    ASSERT_EQUAL(bst.min_element(), bst.end());

    bst.insert(7);
    bst.insert(12);
    bst.insert(20);
    bst.insert(3);
    bst.insert(4);
    bst.insert(0);
    bst.insert(100);
    //       7
    //    3    12
    //  0   4     20
    //               100

    ASSERT_EQUAL(*bst.min_element(), 0);
}

TEST(test_max_element_1){

    BinarySearchTree<int> bst;

    ASSERT_EQUAL(bst.max_element(), bst.end());

    bst.insert(7);
    bst.insert(12);
    bst.insert(20);
    bst.insert(3);
    bst.insert(1);
    bst.insert(2);
    bst.insert(0);
    //       7
    //    3    12
    //  1        20
    //0    2     

    ASSERT_EQUAL(*bst.max_element(), 20);
}

TEST(test_max_element_2){

    BinarySearchTree<int> bst;

    ASSERT_EQUAL(bst.max_element(), bst.end());

    bst.insert(7);
    bst.insert(6);
    bst.insert(5);
    bst.insert(4);
    bst.insert(3);
    bst.insert(2);
    bst.insert(1);
    //       7
    //      6
    //     5
    //    4     
    //   3
    //  2
    // 1
    ASSERT_EQUAL(*bst.max_element(), 7);
}

TEST(test_find){

    BinarySearchTree<int> bst;

    ASSERT_EQUAL(bst.find(0), bst.end());

    bst.insert(7);
    bst.insert(12);
    bst.insert(20);
    bst.insert(3);
    bst.insert(4);
    bst.insert(0);
    bst.insert(100);
    //       7
    //    3    12
    //  0   4     20
    //               100

    ASSERT_EQUAL(bst.find(6), bst.end()); //find sth not exist
    ASSERT_EQUAL(*bst.find(7), 7);
    ASSERT_EQUAL(*bst.find(0), 0);
    ASSERT_EQUAL(*bst.find(4), 4);
    ASSERT_EQUAL(*bst.find(20), 20);
    ASSERT_EQUAL(*bst.find(100), 100);
}

TEST(test_insert){

    BinarySearchTree<int> bst;

    bst.insert(7);
    ASSERT_EQUAL(bst.size(), 1);
    ASSERT_EQUAL(bst.height(), 1);
    ASSERT_EQUAL(*bst.begin(), 7);
    ASSERT_EQUAL(*bst.find(7), 7);

    bst.insert(12);
    ASSERT_EQUAL(bst.size(), 2);
    ASSERT_EQUAL(*(++bst.begin()), 12);
    ASSERT_EQUAL(bst.height(), 2);
    ASSERT_EQUAL(*bst.begin(), 7);
    ASSERT_EQUAL(*bst.find(12), 12);

    bst.insert(3);
    ASSERT_EQUAL(bst.size(), 3);
    ASSERT_EQUAL(*bst.begin(), 3);
    ASSERT_EQUAL(bst.height(), 2);
    ASSERT_EQUAL(*bst.find(3), 3);
//      7
//    3   12
}

TEST(test_sorting_invariant) {

    BinarySearchTree<int> bst1;
    ASSERT_TRUE(bst1.check_sorting_invariant());
    bst1.insert(4);
    bst1.insert(3);
    bst1.insert(5);
//       4
//     3   5
    *(++bst1.begin()) = 7;
    
//       7
//     3   5
    ASSERT_FALSE(bst1.check_sorting_invariant());

    BinarySearchTree<int> bst2;
    ASSERT_TRUE(bst2.check_sorting_invariant());
    bst2.insert(4);
    bst2.insert(3);
    bst2.insert(5);
//       4
//     3   5
    *(bst2.begin()) = 9;
//       4
//     9   5
    ASSERT_FALSE(bst2.check_sorting_invariant());

    BinarySearchTree<int> bst3;
    ASSERT_TRUE(bst3.check_sorting_invariant());
    bst3.insert(4);
    bst3.insert(3);
    bst3.insert(5);
//       4
//     3   5
    *(++++bst3.begin()) = 20;
//       4
//     3   20
    ASSERT_TRUE(bst3.check_sorting_invariant());

    BinarySearchTree<int> bst4;
    ASSERT_TRUE(bst4.check_sorting_invariant());
    bst4.insert(4);
    bst4.insert(3);
    bst4.insert(5);
//       4
//     3   5
    *(++++bst4.begin()) = 1;
//       4
//     3   1
    ASSERT_FALSE(bst4.check_sorting_invariant());

    BinarySearchTree<int> bst5;
    ASSERT_TRUE(bst5.check_sorting_invariant());
    bst5.insert(6);
    bst5.insert(3);
    bst5.insert(1);
    bst5.insert(4);
    bst5.insert(8);
    bst5.insert(10);
//       6
//     3   8
//   1   4   10
    *(++++++++bst5.begin()) = 17;
//       6
//     3   17
//   1   4   10
    ASSERT_FALSE(bst5.check_sorting_invariant());
    *(++++++++++bst5.begin()) = 21;
//       6
//     3   17
//   1   4   21
    ASSERT_TRUE(bst5.check_sorting_invariant());
    
    
}


TEST(test_traverse_preorder_1){

    BinarySearchTree<int> bst;

    bst.insert(7);
    bst.insert(12);
    bst.insert(20);
    bst.insert(3);
    bst.insert(4);
    bst.insert(0);
    bst.insert(100);
    //       7
    //    3    12
    //  0   4     20
    //               100

    std::string expected = "7 3 0 4 12 20 100 ";
    std::ostringstream output;
    bst.traverse_preorder(output);
    ASSERT_EQUAL(output.str(), expected);

}

TEST(test_traverse_preorder_2){

    BinarySearchTree<int> bst;

    bst.insert(7);
    bst.insert(6);
    bst.insert(8);
    bst.insert(5);
    bst.insert(4);
    bst.insert(2);
    bst.insert(3);
    bst.insert(1);
    //       7
    //      6 8
    //     5
    //    4     
    //   2
    // 1   3

    std::string expected = "7 6 5 4 2 1 3 8 ";
    std::ostringstream output;
    bst.traverse_preorder(output);
    ASSERT_EQUAL(output.str(), expected);

}

TEST(test_traverse_preorder_left_stick){

    BinarySearchTree<int> bst;

    bst.insert(7);
    bst.insert(6);
    bst.insert(5);
    bst.insert(4);
    bst.insert(3);
    bst.insert(2);
    bst.insert(1);
    //       7
    //      6 
    //     5
    //    4     
    //   3
    //  2
    // 1

    std::string expected = "7 6 5 4 3 2 1 ";
    std::ostringstream output;
    bst.traverse_preorder(output);
    ASSERT_EQUAL(output.str(), expected);

}

TEST(test_traverse_preorder_right_stick){

    BinarySearchTree<int> bst;

    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);
    bst.insert(6);
    bst.insert(7);
    // 1
    //  2 
    //   3
    //    4     
    //     5
    //      6
    //       7

    std::string expected = "1 2 3 4 5 6 7 ";
    std::ostringstream output;
    bst.traverse_preorder(output);
    ASSERT_EQUAL(output.str(), expected);

}

TEST(test_traverse_preorder_complete_tree){

    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(6);
    bst.insert(15);
    bst.insert(8);
    bst.insert(0);
    bst.insert(13);
    bst.insert(20);
    //      10
    //    6     15
    //  0   8  13  20

    std::string expected = "10 6 0 8 15 13 20 ";
    std::ostringstream output;
    bst.traverse_preorder(output);
    ASSERT_EQUAL(output.str(), expected);

}

TEST(test_traverse_ineorder_1){

    BinarySearchTree<int> bst;

    bst.insert(7);
    bst.insert(12);
    bst.insert(20);
    bst.insert(3);
    bst.insert(4);
    bst.insert(0);
    bst.insert(100);
    //       7
    //    3    12
    //  0   4     20
    //               100

    std::string expected = "0 3 4 7 12 20 100 ";
    std::ostringstream output;
    bst.traverse_inorder(output);
    ASSERT_EQUAL(output.str(), expected);

}

TEST(test_traverse_inorder_2){

    BinarySearchTree<int> bst;

    bst.insert(7);
    bst.insert(6);
    bst.insert(8);
    bst.insert(5);
    bst.insert(4);
    bst.insert(2);
    bst.insert(3);
    bst.insert(1);
    //       7
    //      6 8
    //     5
    //    4     
    //   2
    // 1   3

    std::string expected = "1 2 3 4 5 6 7 8 ";
    std::ostringstream output;
    bst.traverse_inorder(output);
    ASSERT_EQUAL(output.str(), expected);

}

TEST(test_traverse_inorder_left_stick){

    BinarySearchTree<int> bst;

    bst.insert(7);
    bst.insert(6);
    bst.insert(5);
    bst.insert(4);
    bst.insert(3);
    bst.insert(2);
    bst.insert(1);
    //       7
    //      6 
    //     5
    //    4     
    //   3
    //  2
    // 1

    std::string expected = "1 2 3 4 5 6 7 ";
    std::ostringstream output;
    bst.traverse_inorder(output);
    ASSERT_EQUAL(output.str(), expected);

}

TEST(test_traverse_inorder_right_stick){

    BinarySearchTree<int> bst;

    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);
    bst.insert(6);
    bst.insert(7);
    // 1
    //  2 
    //   3
    //    4     
    //     5
    //      6
    //       7

    std::string expected = "1 2 3 4 5 6 7 ";
    std::ostringstream output;
    bst.traverse_inorder(output);
    ASSERT_EQUAL(output.str(), expected);

}

TEST(test_traverse_inorder_complete_tree){

    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(6);
    bst.insert(15);
    bst.insert(8);
    bst.insert(0);
    bst.insert(13);
    bst.insert(20);
    //      10
    //    6     15
    //  0   8  13  20

    std::string expected = "0 6 8 10 13 15 20 ";
    std::ostringstream output;
    bst.traverse_inorder(output);
    ASSERT_EQUAL(output.str(), expected);

}

TEST(test_min_greater_than_1)
{
    BinarySearchTree<int> bst;
    ASSERT_EQUAL(bst.min_greater_than(100), bst.end());

    bst.insert(7);
    bst.insert(12);
    bst.insert(20);
    bst.insert(3);
    bst.insert(4);
    bst.insert(0);
    bst.insert(100);
    //       7
    //    3    12
    //  0   4     20
    //               100

    ASSERT_EQUAL(*bst.min_greater_than(0), 3);
    ASSERT_EQUAL(*bst.min_greater_than(4), 7);
    ASSERT_EQUAL(*bst.min_greater_than(20), 100);
    ASSERT_EQUAL(*bst.min_greater_than(17), 20);
}

TEST(test_double_value_type)
{
    BinarySearchTree<double> bst;

    bst.insert(6.5);
    bst.insert(6.51);
    bst.insert(6.66666);
    bst.insert(0.1);
    bst.insert(4);
    bst.insert(2.0);
    bst.insert(3);
    bst.insert(1.00);
    //       6.5
    //    0.1   6.51
    //       4      6.66666
    //     2  
    //   1   3

    ASSERT_EQUAL(*bst.min_element(), 0.1);
    ASSERT_EQUAL(*bst.max_element(), 6.66666);
    ASSERT_EQUAL(*bst.min_greater_than(0.1), 1);
    ASSERT_EQUAL(*bst.min_greater_than(3), 4);

    std::string expected_inorder = "0.1 1 2 3 4 6.5 6.51 6.66666 ";
    std::ostringstream output_inorder;
    bst.traverse_inorder(output_inorder);
    ASSERT_EQUAL(output_inorder.str(), expected_inorder);

    std::string expected_preorder = "6.5 0.1 4 2 1 3 6.51 6.66666 ";
    std::ostringstream output_preorder;
    bst.traverse_preorder(output_preorder);
    ASSERT_EQUAL(output_preorder.str(), expected_preorder);

}

TEST(test_char_value_type)
{
    BinarySearchTree<double> bst;

    bst.insert('l');
    bst.insert('p');
    bst.insert('a');
    bst.insert('b');
    bst.insert('u');
    bst.insert('t');
    bst.insert('g');
    bst.insert('m');
    //          l
    //     a         p  
    //       b     m   u
    //         g      t

    ASSERT_EQUAL(*bst.min_element(), 97);
    ASSERT_EQUAL(*bst.max_element(), 117);
    ASSERT_EQUAL(*bst.min_greater_than('g'), 'l');
    ASSERT_EQUAL(*bst.min_greater_than('p'), 't');

    std::string expected_inorder = "97 98 103 108 109 112 116 117 ";
    std::ostringstream output_inorder;
    bst.traverse_inorder(output_inorder);
    ASSERT_EQUAL(output_inorder.str(), expected_inorder);

    std::string expected_preorder = "108 97 98 103 112 109 117 116 ";
    std::ostringstream output_preorder;
    bst.traverse_preorder(output_preorder);
    ASSERT_EQUAL(output_preorder.str(), expected_preorder);

}




TEST_MAIN()
