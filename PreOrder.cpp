/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */
#include "tree.hpp"

/**
 * This class represents an iterator for performing a pre-order traversal on a tree structure.
*/

/**
 * Constructs the iterator with the given root node.
 * 
 * If the root is not null:
 * For binary trees (maxChilds == 2), it directly traverses the tree, otherwise populates a stack for K-ary trees.
 * Sets the current node to the front of the pre-order nodes stack.
 * If the root is null, sets the current node to null.
*/
template <typename T>
tree<T>::PreOrderIterator::PreOrderIterator(Node<T> *root)
{
    if (root) {
        if (root->maxChilds == 2) {
            traverse(root);
            current = pre_order_nodes.empty() ? nullptr : pre_order_nodes.front();
        } else {
            nodes.push(root);
            populatepreOrderStack();
            current = pre_order_nodes.empty() ? nullptr : pre_order_nodes.front();
        }
    } else {
        current = nullptr;
    }
}

// Recursively traverses the tree and pushes nodes onto the pre-order nodes stack before traversing child nodes.
template <typename T>
void tree<T>::PreOrderIterator::traverse(Node<T> *node)
{
    if (!node)
        return;
    pre_order_nodes.push(node);
    
    for (auto child : node->children) {
        traverse(child);
    }
}

/**
 * This method is responsible for populating the pre-order nodes stack for K-ary trees. 
 * 
 * It initializes an auxiliary stack (auxStack) to hold child nodes temporarily.
 * The method iterates while the main stack (nodes) is not empty:
 * Pops a node from the main stack and pushes it onto the post_order_nodes stack.
 * For each child node of the current node:
 * If the child node exists (i.e., is not null), it is pushed onto the auxiliary stack.
 * After processing all children, the method transfers nodes from the auxiliary stack back to the main stack to handle them 
 * in the correct order.
 */
template <typename T>
void tree<T>::PreOrderIterator::populatepreOrderStack()
{
    std::stack<Node<T> *> auxStack;
    while (!nodes.empty())
    {
        Node<T> *node = nodes.top();
        nodes.pop();
        pre_order_nodes.push(node);
        for (auto child : node->children)
        {
            if (child)
            {
                auxStack.push(child);
            }
        }
        while (!auxStack.empty())
        {
            nodes.push(auxStack.top());
            auxStack.pop();
        }
    }
}
//Dereference operator that returns the value of the current node or throws a runtime error if the node is null.
template <typename T>
T &tree<T>::PreOrderIterator::operator*() const
{
    if (current) {
        return current->value;
    } else {
        throw std::runtime_error("Dereferencing a null pointer");
    }
}
// Pre-increment operator that pops the current node from the pre-order nodes stack.
template <typename T>
typename tree<T>::PreOrderIterator &tree<T>::PreOrderIterator::operator++()
{
    if (pre_order_nodes.size() > 0)
    {
        pre_order_nodes.pop();
        current = pre_order_nodes.empty() ? nullptr : pre_order_nodes.front();
    }
    return *this;
}
// Equality operator checking if two iterators are at the same position.
template <typename T>
bool tree<T>::PreOrderIterator::operator==(const PreOrderIterator &rhs) const
{
    return current == rhs.current && pre_order_nodes == rhs.pre_order_nodes;
}
// Inequality operator checking if two iterators are at different positions.
template <typename T>
bool tree<T>::PreOrderIterator::operator!=(const PreOrderIterator &rhs) const
{
    return !(*this == rhs);
}

/**
 * It explicitly instantiates the PreOrderIterator class for various types (int, float, double, char, string, Complex).
 * This allows the compiler to generate the necessary code for these specific types.
*/
template class tree<int>::PreOrderIterator;
template class tree<float>::PreOrderIterator;
template class tree<double>::PreOrderIterator;
template class tree<char>::PreOrderIterator;
template class tree<string>::PreOrderIterator;
template class tree<Complex>::PreOrderIterator;
