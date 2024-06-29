/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */
#include <iostream>
#include "tree.hpp"

#include "Complex.hpp"

/**
 * Demo class to represnt K-ary tree
*/

int main() {

    // 3 - ary tree
    tree<Complex> tree1; // Creating a tree with complex numbers
    Complex rootNum(7, 7); // Root node with complex number (0+0i): origin

    // Create the k-ary tree1 with complex numbers
    Node<Complex>* root = tree1.add_root(rootNum,3);

    tree1.add_sub_node(root, Complex(0, 0));  // Children nodes with complex numbers
    tree1.add_sub_node(root, Complex(2, 2));
    tree1.add_sub_node(root, Complex(3, 3));

    Node<Complex>* secondChild = root->children[1]; 

    tree1.add_sub_node(secondChild, Complex(4, 4));
    tree1.add_sub_node(secondChild, Complex(1, 1));

    Node<Complex>* thirdChild = root->children[2];
  
    tree1.add_sub_node(thirdChild, Complex(5, 5));
    tree1.add_sub_node(thirdChild, Complex(6, 6));
    tree1.add_sub_node(thirdChild, Complex(8, 8));

    // Binary tree
    tree<char> tree2;

    Node<char>* root2 = tree2.add_root('A');

    tree2.add_sub_node(root2, 'B');
    tree2.add_sub_node(root2, 'C');

    Node<char>* secondChild2 = root2->children[0];

    tree2.add_sub_node(secondChild2, 'D');
    tree2.add_sub_node(secondChild2, 'E');

    // Binary tree of complex
    tree<Complex> tree3;

    Node<Complex>* root3 = tree3.add_root(Complex(1,1));

    tree3.add_sub_node(root3, Complex(2,2));
    tree3.add_sub_node(root3, Complex(3,3));

    Node<Complex>* secondChild3 = root3->children[0];

    tree3.add_sub_node(secondChild3, Complex(4,4));
    tree3.add_sub_node(secondChild3, Complex(5,5));

    cout << "===================================================================" << endl;
    cout << "3-ary tree of compex numbers" << endl;
    cout << "===================================================================\n" << endl;

    // Pre-order traversal
    std::cout << "Pre-order traversal:" << std::endl;
    for (auto it = tree1.begin_pre_order(); it != tree1.end_pre_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Post-order traversal
    std::cout << "Post-order traversal:" << std::endl;
    for (auto it = tree1.begin_post_order(); it != tree1.end_post_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // In-order traversal (only valid for binary tree1)
    std::cout << "In-order traversal:" << std::endl;
    for (auto it = tree1.begin_in_order(); it != tree1.end_in_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // BFS traversal
    std::cout << "BFS traversal:" << std::endl;
    for (auto it = tree1.begin_bfs_scan(); it != tree1.end_bfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // DFS traversal
    std::cout << "DFS traversal:" << std::endl;
    for (auto it = tree1.begin_dfs_scan(); it != tree1.end_dfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Heap traversal
    std::cout << "Min Heap traversal:" << std::endl;
    tree1.myHeap();
    std::cout << std::endl;
    std::cout <<'\n'<< std::endl;

    TreeGUI<Complex> gui1(tree1);  
    gui1.run();

    cout << "===================================================================" << endl;
    cout << "Binary tree of chars" << endl;
    cout << "===================================================================\n" << endl;

    // Pre-order traversal
    std::cout << "Pre-order traversal:" << std::endl;
    for (auto it = tree2.begin_pre_order(); it != tree2.end_pre_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Post-order traversal
    std::cout << "Post-order traversal:" << std::endl;
    for (auto it = tree2.begin_post_order(); it != tree2.end_post_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // In-order traversal (only valid for binary tree1)
    std::cout << "In-order traversal:" << std::endl;
    for (auto it = tree2.begin_in_order(); it != tree2.end_in_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // BFS traversal
    std::cout << "BFS traversal:" << std::endl;
    for (auto it = tree2.begin_bfs_scan(); it != tree2.end_bfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // DFS traversal
    std::cout << "DFS traversal:" << std::endl;
    for (auto it = tree2.begin_dfs_scan(); it != tree2.end_dfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Heap traversal
    std::cout << "Heap traversal:" << std::endl;
    tree2.myHeap();
    std::cout << std::endl;
    std::cout <<'\n'<< std::endl;

    TreeGUI<char> gui2(tree2);  
    gui2.run();

    cout << "===================================================================" << endl;
    cout << "Binary tree of complex numbers" << endl;
    cout << "===================================================================\n" << endl;

    // Pre-order traversal
    std::cout << "Pre-order traversal:" << std::endl;
    for (auto it = tree3.begin_pre_order(); it != tree3.end_pre_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Post-order traversal
    std::cout << "Post-order traversal:" << std::endl;
    for (auto it = tree3.begin_post_order(); it != tree3.end_post_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // In-order traversal (only valid for binary tree1)
    std::cout << "In-order traversal:" << std::endl;
    for (auto it = tree3.begin_in_order(); it != tree3.end_in_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // BFS traversal
    std::cout << "BFS traversal:" << std::endl;
    for (auto it = tree3.begin_bfs_scan(); it != tree3.end_bfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // DFS traversal
    std::cout << "DFS traversal:" << std::endl;
    for (auto it = tree3.begin_dfs_scan(); it != tree3.end_dfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Heap traversal
    std::cout << "Min Heap traversal:" << std::endl;
    tree3.myHeap();
    std::cout << std::endl;

    TreeGUI<Complex> gui3(tree3);  
    gui3.run();


    return 0;
}
