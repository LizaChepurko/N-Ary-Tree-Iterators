/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */
#include "tree.hpp"
/**
 * This class represents an iterator for performing a breadth-first search traversal on a tree structure.
*/

/**
 * Constructs the iterator with the given root node if not null.
 * If the root is provided, it initializes the queue with the root node.
*/
template <typename T>
tree<T>::BFSIterator::BFSIterator(Node<T> *root) {
    if (root) {
        nodes.push(root);
    }
    else
    {
        current = nullptr;
    }
}
// Dereference operator that returns the value of the current node at the front of the queue.
template <typename T>
T &tree<T>::BFSIterator::operator*() {
    if (current) {
        return nodes.front()->value;
    } else {
        throw std::runtime_error("Dereferencing a null pointer");
    }
}
// Pre-increment operator that traverses the tree in a breadth-first manner by enqueueing child nodes from left to right.
template <typename T>
typename tree<T>::BFSIterator &tree<T>::BFSIterator::operator++() {
    if (!nodes.empty()) {
        Node<T>* node = nodes.front();
        nodes.pop();
        // Enqueue children from left to right
        for (auto child : node->children) {
            if (child) {
                nodes.push(child);
            }
        }
    }
    return *this;
}
// Equality operator checking if two iterators hold the same queue content.
template <typename T>
bool tree<T>::BFSIterator::operator==(const BFSIterator &rhs) const {
    return nodes == rhs.nodes;
}
// Inequality operator checking if two iterators hold different queue content.
template <typename T>
bool tree<T>::BFSIterator::operator!=(const BFSIterator &other) const {
    return nodes != other.nodes;
}

/**
 * The class is explicitly instantiated for various types (int, char, float, double, string, Complex).
 * This instantiation ensures that specific implementations of the iterator are generated for each of these data types.
*/
template class tree<int>::BFSIterator;
template class tree<char>:: BFSIterator;
template class tree<float>::BFSIterator;
template class tree<double>:: BFSIterator;
template class tree<string>::BFSIterator;
template class tree<Complex>::BFSIterator;
