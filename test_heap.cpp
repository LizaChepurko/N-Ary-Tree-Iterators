/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */
#include <gtest/gtest.h>
#include "tree.hpp"
#include "Heap.cpp"

// Test case to check if dereferencing a null pointer throws std::runtime_error
TEST(MinHeapIteratorTest, DereferenceNullPointer) {
    Node<int> *root = nullptr;

    tree<int>::MinHeapIterator iterator(root);

    // Testing dereferencing a null pointer scenario
    EXPECT_THROW({
        *iterator; 
    }, std::runtime_error);
}

TEST(MinHeapTest, KaryTreeTraversal) {
    tree<int> tree1;

    EXPECT_THROW({
       tree1.myHeap(); //tree is empty
    }, std::runtime_error);

    tree1.add_root(7, 3);

    ASSERT_NO_THROW(tree1.add_sub_node(tree1.get_root(), 3));
    ASSERT_NO_THROW(tree1.add_sub_node(tree1.get_root(), 9));
    ASSERT_NO_THROW(tree1.add_sub_node(tree1.get_root(), 5));

    Node<int>* firstChild = tree1.get_root()->children[0]; // node value 3
    Node<int>* secondChild = tree1.get_root()->children[1]; // node value 9


    ASSERT_NO_THROW(tree1.add_sub_node(firstChild, 1));
    ASSERT_NO_THROW(tree1.add_sub_node(firstChild, 4));
    ASSERT_NO_THROW(tree1.add_sub_node(secondChild, 10));

    std::ostringstream oss;
    tree1.myHeap(oss);
    EXPECT_EQ(oss.str(), "1 3 4 5 7 9 10 ");
}

TEST(MinHeapTest, BinaryTreeTraversal) {

    //example from: https://www.geeksforgeeks.org/introduction-to-min-heap-data-structure/
    tree<int> tree1;

    EXPECT_THROW({
       tree1.myHeap(); //tree is empty
    }, std::runtime_error);

    tree1.add_root(100);

    ASSERT_NO_THROW(tree1.add_sub_node(tree1.get_root(), 16));
    ASSERT_NO_THROW(tree1.add_sub_node(tree1.get_root(), 31));

    Node<int>* firstChild = tree1.get_root()->children[0]; // node value 16


    ASSERT_NO_THROW(tree1.add_sub_node(firstChild, 41));
    ASSERT_NO_THROW(tree1.add_sub_node(firstChild, 51));

    std::ostringstream oss;
    tree1.myHeap(oss);
    EXPECT_EQ(oss.str(), "16 31 41 51 100 ");
}