/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include <gtest/gtest.h>
#include "tree.hpp"
#include "InOrder.cpp"


// Test case to check if dereferencing a null pointer throws std::runtime_error
TEST(InOrderIteratorTest, DereferenceNullPointer) {
    Node<int> *root = nullptr;

    tree<int>::InOrderIterator iterator(root);

    // Testing dereferencing a null pointer scenario
    EXPECT_THROW({
        *iterator; 
    }, std::runtime_error);
}


TEST(INORDERtest, tst1_3ary) {

    // example from here: https://www.geeksforgeeks.org/inorder-traversal-of-an-n-ary-tree/
    tree<int> tree;


    tree.add_root(1,3);

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 2));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 3));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 4));

    Node<int>* secondChild = tree.get_root()->children[0]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 5));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 6));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 7));

    int preorder_expected[7];
    int preorder_result[7];
    int i = 0;

    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        preorder_expected[i] = *it;
        i++;
    }
    
    i = 0;

    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        preorder_result[i] = *it;
        cout<<*it<<" ";
        i++;
    }

    for(int i = 0; i<7; i++){
        ASSERT_EQ(preorder_result[i] , preorder_expected[i]);
    }
}


TEST(INORDERtest, tst2Binary) {

    tree<int> tree;

    // Create the k-ary tree
    Node<int>* root = tree.add_root(1);
    tree.add_sub_node(root, 2);
    tree.add_sub_node(root, 3);

    Node<int>* secondChild = root->children[0]; // Node with value 3

    tree.add_sub_node(secondChild, 4);
    tree.add_sub_node(secondChild, 5);

    Node<int>* ThirdChild = root->children[1];

    tree.add_sub_node(ThirdChild, 6);
    tree.add_sub_node(ThirdChild, 7);

    int preorder_expected[7] = {4,2,5,1,6,3,7};
    int preorder_result[7];
    int i = 0;

    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        preorder_result[i] = *it;
        cout<<*it<<" ";
        i++;
    }

    for(int i = 0; i<7; i++){
        ASSERT_EQ(preorder_result[i] , preorder_expected[i]);
    }
}

TEST(INORDERtest_binary, tst2) {

    // example from here: https://www.geeksforgeeks.org/inorder-traversal-of-binary-tree/
    tree<int> tree;


    tree.add_root(1);

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 2));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 3));

    Node<int>* secondChild = tree.get_root()->children[0]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 4));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 5));

    Node<int>* thirdChild = tree.get_root()->children[1]; // node value 3

    ASSERT_NO_THROW(tree.add_sub_node(thirdChild, 6));

    int preorder_expected[6] = {4,2,5,1,3,6};
    int preorder_result[6];
    int i = 0;

    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        preorder_result[i] = *it;
        cout<<*it<<" ";
        i++;
    }

    for(int i = 0; i < 6; i++){
        ASSERT_EQ(preorder_result[i] , preorder_expected[i]);
    }
}

// Same as the previouse test but with complex numbers
TEST(INORDERtest_binary, tst2Complex) {

    tree<Complex> tree;


    tree.add_root(Complex(1,1));

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), Complex(2,2)));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), Complex(3,3)));

    Node<Complex>* secondChild = tree.get_root()->children[0]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(secondChild, Complex(4,4)));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, Complex(5,5)));

    Node<Complex>* thirdChild = tree.get_root()->children[1]; // node value 3

    ASSERT_NO_THROW(tree.add_sub_node(thirdChild, Complex(6,6)));

    Complex preorder_expected[6] = {Complex(4,4),Complex(2,2),Complex(5,5),Complex(1,1),Complex(3,3),Complex(6,6)};
    Complex preorder_result[6];
    int i = 0;

    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        preorder_result[i] = *it;
        cout<<*it<<" ";
        i++;
    }

    for(int i = 0; i < 6; i++){
        ASSERT_EQ(preorder_result[i] , preorder_expected[i]);
    }
}
