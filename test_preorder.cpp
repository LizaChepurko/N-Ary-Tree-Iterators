/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include <gtest/gtest.h>
#include "tree.hpp"
#include "PreOrder.cpp"


// Test case to check if dereferencing a null pointer throws std::runtime_error
TEST(PreOrderIteratorTest, DereferenceNullPointer) {
    Node<int> *root = nullptr;

    tree<int>::PreOrderIterator iterator(root);

    // Testing dereferencing a null pointer scenario
    EXPECT_THROW({
        *iterator; 
    }, std::runtime_error);
}

TEST(PREORDERtest_3_ary_tree, tst1) {
    // example from here: https://www.geeksforgeeks.org/preorder-traversal-of-a-n-ary-tree/
    tree<int> tree;

    tree.add_root(1,3);

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 2));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 3));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 4));

    Node<int>* secondChild = tree.get_root()->children[0]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 5));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 6));

    Node<int>* ThirdChild = tree.get_root()->children[2]; // node value 4

    ASSERT_NO_THROW(tree.add_sub_node(ThirdChild, 7));
    ASSERT_NO_THROW(tree.add_sub_node(ThirdChild, 8));
    ASSERT_NO_THROW(tree.add_sub_node(ThirdChild, 9));

    Node<int>* lvl_3_child_1 = tree.get_root()->children[0]->children[0]; // node value 5

    ASSERT_NO_THROW(tree.add_sub_node(lvl_3_child_1, 10));

    Node<int>* lvl_3_child_2 = tree.get_root()->children[0]->children[1]; // node value 6

    ASSERT_NO_THROW(tree.add_sub_node(lvl_3_child_2, 11));
    ASSERT_NO_THROW(tree.add_sub_node(lvl_3_child_2, 12));
    ASSERT_NO_THROW(tree.add_sub_node(lvl_3_child_2, 13));
        

    int preorder_expected[13];
    int preorder_result[13];
    int i = 0;


    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        preorder_expected[i] = *it;
        i++;
    }

    i = 0;

    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        preorder_result[i] = *it;
        i++;
    }

    for(int i = 0; i<13; i++){
        ASSERT_EQ(preorder_result[i] , preorder_expected[i]);
    }
}

TEST(PREORDERtest_binary_tree, tst2) {
    //exemple from: https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
    tree<int> tree;

    tree.add_root(1);

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 2));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 3));

    Node<int>* secondChild = tree.get_root()->children[0]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 4));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 5));

    Node<int>* thirdChild = tree.get_root()->children[1]; // node value 3

    ASSERT_NO_THROW(tree.add_sub_node(thirdChild, 6));

    int preorder_expected[6] = {1,2,4,5,3,6};
    int preorder_result[6];

    int i = 0;

    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        preorder_result[i] = *it;
        i++;
    }

    for(int i = 0; i<6; i++){
        ASSERT_EQ(preorder_result[i] , preorder_expected[i]);
    }
}

// Same as the previouse test but with complex numbers
TEST(PREORDERtest_binary_tree, tst2Complex) {

    tree<Complex> tree;

    tree.add_root(Complex(1,1));

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), Complex(2,2)));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), Complex(3,3)));

    Node<Complex>* secondChild = tree.get_root()->children[0]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(secondChild, Complex(4,4)));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, Complex(5,5)));

    Node<Complex>* thirdChild = tree.get_root()->children[1]; // node value 3

    ASSERT_NO_THROW(tree.add_sub_node(thirdChild, Complex(6,6)));

    Complex preorder_expected[6] = {Complex(1,1),Complex(2,2),Complex(4,4),Complex(5,5),Complex(3,3),Complex(6,6)};
    Complex preorder_result[6];

    int i = 0;

    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        preorder_result[i] = *it;
        i++;
    }

    for(int i = 0; i<6; i++){
        ASSERT_EQ(preorder_result[i] , preorder_expected[i]);
    }
}