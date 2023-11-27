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
//      100
//  50       150
//30  70  120   160

}

TEST(test_height_one_side){

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

TEST(test_copy_nodes){

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

    ASSERT_EQUAL(++bst.find(18), bst.end());
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

    //ASSERT_EQUAL(bst.find(6), bst.end()); //find sth not exist
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
}


//still need TEST
//traverse_inorder(), traverse_preorder(),
//sorting_invariant(), min_greater()


TEST_MAIN()
