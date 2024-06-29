/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */
#include <gtest/gtest.h>
#include "tree.hpp"
#include "DFS.cpp"

// Test case to check if dereferencing a null pointer throws std::runtime_error
TEST(DFSIteratorTest, DereferenceNullPointer) {
    Node<int> *root = nullptr;

    tree<int>::DFSIterator iterator(root);

    // Testing dereferencing a null pointer scenario
    EXPECT_THROW({
        *iterator; 
    }, std::runtime_error);
}

TEST(DFSTest, KaryTreeTraversal) {
    tree<int> tree;

    tree.add_root(1, 3);

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 2));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 3));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 4));

    Node<int>* firstChild = tree.get_root()->children[0]; // node value 2
    Node<int>* secondChild = tree.get_root()->children[1]; // node value 3

    ASSERT_NO_THROW(tree.add_sub_node(firstChild, 5));
    ASSERT_NO_THROW(tree.add_sub_node(firstChild, 6));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 7));

    int dfs_expected[7] = {1, 2, 5, 6, 3, 7, 4};
    int dfs_result[7];
    int i = 0;

    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        dfs_result[i] = *it;
        i++;
    }

    for (int i = 0; i < 7; ++i) {
        ASSERT_EQ(dfs_result[i], dfs_expected[i]);
    }
}


TEST(DFSTest, BinaryTreeTraversal) {
    tree<int> tree;

    tree.add_root(0);

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 1));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 2));

    Node<int>* firstChild = tree.get_root()->children[0]; // node value 1
    Node<int>* secondChild = tree.get_root()->children[1]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(firstChild, 3));
    ASSERT_NO_THROW(tree.add_sub_node(firstChild, 4));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 5));

    int dfs_expected[6] = {0, 1, 3, 4, 2, 5};
    int dfs_result[6];
    int i = 0;

    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        dfs_result[i] = *it;
        i++;
    }

    for (int i = 0; i < 6; ++i) {
        ASSERT_EQ(dfs_result[i], dfs_expected[i]);
    }
}

// Same as the previouse test but with complex numbers
TEST(DFSTest, BinaryTreeTraversalComplex) {
    tree<Complex> tree;

    tree.add_root(Complex(0,0));

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), Complex(1,1)));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), Complex(2,2)));

    Node<Complex>* firstChild = tree.get_root()->children[0]; // node value 1 + 1i
    Node<Complex>* secondChild = tree.get_root()->children[1]; // node value 2 + 2i

    ASSERT_NO_THROW(tree.add_sub_node(firstChild, Complex(3,3)));
    ASSERT_NO_THROW(tree.add_sub_node(firstChild, Complex(4,4)));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, Complex(5,5)));

    Complex dfs_expected[6] = {Complex(0,0), Complex(1,1), Complex(3,3), Complex(4,4), Complex(2,2), Complex(5,5)};
    Complex dfs_result[6];
    int i = 0;

    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        dfs_result[i] = *it;
        i++;
    }

    for (int i = 0; i < 6; ++i) {
        ASSERT_EQ(dfs_result[i], dfs_expected[i]);
    }
}