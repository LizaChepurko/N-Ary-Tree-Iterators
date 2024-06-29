/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include <gtest/gtest.h>
#include "tree.hpp"


TEST(KARYTREEtest, insert_1) {
    tree<int> tree;

    EXPECT_THROW({
        tree.get_root_value();
    }, std::runtime_error);

    EXPECT_THROW({
        tree.get_root();
    }, std::runtime_error);

    tree.add_root(1);

    ASSERT_TRUE(1 == tree.get_root_value());

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 5));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 3));

    EXPECT_THROW({
        tree.add_sub_node(tree.get_root(), 6); //max childres is 2
    }, std::runtime_error);

}

TEST(KARYTREEtest, insert_2) {
    tree<int> tree;

    EXPECT_THROW({
        tree.get_root_value();
    }, std::runtime_error);

    EXPECT_THROW({
        tree.get_root();
    }, std::runtime_error);

    tree.add_root(10,5); // every node has max of 5 childs

    ASSERT_TRUE(10 == tree.get_root_value());

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 5));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 3));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 6));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 2));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 1));

    EXPECT_THROW({
        tree.add_sub_node(tree.get_root(), 9); //max childes is 5
    }, std::runtime_error);


    Node<int>* secondChild = tree.get_root()->children[0];

    ASSERT_NO_THROW(tree.add_sub_node(secondChild, 5));

}

TEST(KARYTREEtest, treeWithChar2ary) {
    tree<char> tree;

    EXPECT_THROW({
        tree.get_root_value();
    }, std::runtime_error);

    EXPECT_THROW({
        tree.get_root();
    }, std::runtime_error);

    tree.add_root('A');

    ASSERT_TRUE('A' == tree.get_root_value());

    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 'E'));
    ASSERT_NO_THROW(tree.add_sub_node(tree.get_root(), 'C'));

    EXPECT_THROW({
        tree.add_sub_node(tree.get_root(), 'G'); //max childres is 2
    }, std::runtime_error);

}
