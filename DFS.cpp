/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */
#include "tree.hpp"

/**
 * This class represents an iterator for performing a depth-first search traversal on a tree structure.
 */

/**
 * Constructs the iterator with the given root node if not null.
 * If the root is provided, it initializes the stack with the root node.
 */
template <typename T>
tree<T>::DFSIterator::DFSIterator(Node<T> *root)
{
    if (root)
    {
        nodes.push(root);
    }
    else
    {
        current = nullptr;
    }
}

// Dereference operator that returns the value of the current node at the top of the stack.
template <typename T>
T &tree<T>::DFSIterator::operator*()
{
    if (current)
    {
        return nodes.top()->value;
    }
    else
    {
        throw std::runtime_error("Dereferencing a null pointer");
    }
}

// Pre-increment operator that traverses the tree in a depth-first manner by pushing children
// nodes onto the stack in reverse order (from right to left).
template <typename T>
typename tree<T>::DFSIterator &tree<T>::DFSIterator::operator++()
{
    if (!nodes.empty())
    {
        Node<T> *node = nodes.top();
        nodes.pop();
        // Push children in reverse order (right to left) onto stack
        for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
        {
            if (*it)
            {
                nodes.push(*it);
            }
        }
    }
    return *this;
}
// Equality operator checking if two iterators hold the same stack content.
template <typename T>
bool tree<T>::DFSIterator::operator==(const DFSIterator &rhs) const
{
    return nodes == rhs.nodes;
}
// Inequality operator checking if two iterators hold different stack content.
template <typename T>
bool tree<T>::DFSIterator::operator!=(const DFSIterator &other) const
{
    return nodes != other.nodes;
}

/**
 * The class is explicitly instantiated for various types (int, char, float, double, string, Complex).
 * This instantiation ensures that specific implementations of the iterator are generated for each of these data types.
 */
template class tree<int>::DFSIterator;
template class tree<char>::DFSIterator;
template class tree<float>::DFSIterator;
template class tree<double>::DFSIterator;
template class tree<string>::DFSIterator;
template class tree<Complex>::DFSIterator;
