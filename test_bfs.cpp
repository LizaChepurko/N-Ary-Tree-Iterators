/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */
#include <gtest/gtest.h>
#include "tree.hpp"
#include "BFS.cpp"

// Test case to check if dereferencing a null pointer throws std::runtime_error
TEST(BFSIteratorTest, DereferenceNullPointer) {
    Node<int> *root = nullptr;

    tree<int>::BFSIterator iterator(root);

    // Testing dereferencing a null pointer scenario
    EXPECT_THROW({
        *iterator; 
    }, std::runtime_error);
}

TEST(BFSTest, KaryTreeTraversal) {
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

    int bfs_expected[7] = {1, 2, 3, 4, 5, 6, 7};
    int bfs_result[7];
    int i = 0;

    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        bfs_result[i] = *it;
        i++;
    }

    for (int i = 0; i < 7; ++i) {
        ASSERT_EQ(bfs_result[i], bfs_expected[i]);
    }
}

TEST(BFSTest, KaryTreeTraversal_Chars) {
    tree<int> tree;

    tree.add_root('A', 3);

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 'B'));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 'C'));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 'D'));

    Node<int>* firstChild = tree.get_root()->children[0]; // node value 2
    Node<int>* secondChild = tree.get_root()->children[1]; // node value 3

    ASSERT_NO_THROW(tree.add_sub_node(firstChild, 'E'));
    ASSERT_NO_THROW(tree.add_sub_node(firstChild, 'F'));
    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 'G'));

    int bfs_expected[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int bfs_result[7];
    int i = 0;

    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        bfs_result[i] = *it;
        i++;
    }

    for (int i = 0; i < 7; ++i) {
        ASSERT_EQ(bfs_result[i], bfs_expected[i]);
    }
}

TEST(BFSTest, BinaryTreeTraversal) {
    //example from: https://www.geeksforgeeks.org/level-order-tree-traversal/
    tree<int> tree;

    tree.add_root(1);

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 2));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 3));

    Node<int>* firstChild = tree.get_root()->children[0]; // node value 2

    ASSERT_NO_THROW(tree.add_sub_node(firstChild, 4));
    ASSERT_NO_THROW(tree.add_sub_node(firstChild, 5));

    int bfs_expected[5] = {1, 2, 3, 4, 5};
    int bfs_result[5];
    int i = 0;

    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        bfs_result[i] = *it;
        i++;
    }

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(bfs_result[i], bfs_expected[i]);
    }
}
// Same as the previouse test but with complex numbers
TEST(BFSTest, BinaryTreeTraversalComplex) {
    
    tree<Complex> tree;

    tree.add_root(Complex(1,1));

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), Complex(2,2)));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), Complex(3,3)));

    Node<Complex>* firstChild = tree.get_root()->children[0]; // node value 2 + 2i

    ASSERT_NO_THROW(tree.add_sub_node(firstChild, Complex(4,4)));
    ASSERT_NO_THROW(tree.add_sub_node(firstChild, Complex(5,5)));

    Complex bfs_expected[5] = {Complex(1,1), Complex(2,2), Complex(3,3), Complex(4,4), Complex(5,5)};
    Complex bfs_result[5];
    int i = 0;

    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        bfs_result[i] = *it;
        i++;
    }

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(bfs_result[i], bfs_expected[i]);
    }
}
