/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include <gtest/gtest.h>
#include "tree.hpp"
#include "PostOrder.cpp"

// Test case to check if dereferencing a null pointer throws std::runtime_error
TEST(PostOrderIteratorTest, DereferenceNullPointer) {
    Node<int> *root = nullptr;

    tree<int>::PostOrderIterator iterator(root);

    // Testing dereferencing a null pointer scenario
    EXPECT_THROW({
        *iterator; 
    }, std::runtime_error);
}


TEST(POSTORDERtest_3_ary_tree, tst1) {
    // example from here: https://www.geeksforgeeks.org/iterative-postorder-traversal-of-n-ary-tree/
    tree<int> tree;

    tree.add_root(1,3);

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 3));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 2));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 4));

    Node<int>* secondChild = tree.get_root()->children[0]; // node value 3

    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 5));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 6));

    int postorder_expected[6];
    int postorder_result[6];
    int i = 0;

    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        postorder_expected[i] = *it;
        i++;
    }
    i = 0;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        postorder_result[i] = *it;
        i++;
    }

    for(int i = 0; i<6; i++){
        ASSERT_EQ(postorder_result[i] , postorder_expected[i]);
    }
}

TEST(POSTORDERtest_binary_tree, tst2) {
    // exemple from here: https://www.geeksforgeeks.org/postorder-traversal-of-binary-tree/
    tree<int> tree;

    tree.add_root(1);

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 2));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 3));

    Node<int>* secondChild = tree.get_root()->children[0]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 4));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 5));

    Node<int>* thirdChild = tree.get_root()->children[1]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(thirdChild, 6));

    int postorder_expected[6] = {4,5,2,6,3,1};
    int postorder_result[6];

        int j = 0;

    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        postorder_result[j] = *it;
        j++;
    }

    for(int i = 0; i<6; i++){
        ASSERT_EQ(postorder_result[i] , postorder_expected[i]);
    }
}

// Same as the previouse test but with complex numbers
TEST(POSTORDERtest_binary_tree, tst2Complex) {

    tree<Complex> tree;

    tree.add_root(Complex(1,1));

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), Complex(2,2)));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), Complex(3,3)));

    Node<Complex>* secondChild = tree.get_root()->children[0]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(secondChild, Complex(4,4)));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, Complex(5,5)));

    Node<Complex>* thirdChild = tree.get_root()->children[1]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(thirdChild, Complex(6,6)));

    Complex postorder_expected[6] = {Complex(4,4),Complex(5,5),Complex(2,2),Complex(6,6),Complex(3,3),Complex(1,1)};
    Complex postorder_result[6];

        int j = 0;

    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        postorder_result[j] = *it;
        j++;
    }

    for(int i = 0; i<6; i++){
        ASSERT_EQ(postorder_result[i] , postorder_expected[i]);
    }
}