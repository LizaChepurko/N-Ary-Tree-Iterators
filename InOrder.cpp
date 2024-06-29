/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */
#include "tree.hpp"

/**
 * This class represents an iterator for performing a in-order traversal on a tree structure.
*/

/**
 * Constructs the iterator with the given root node and determines whether the tree is binary or not.
 * If the root is not null:
 * For binary trees, it performs a traversal, split at the middle, and pushes nodes into the in-order queue.
 * For non-binary trees, it processes nodes in a specific order based on the split traversal logic.
 * Sets the current node to the front of the in-order queue.
 * If the root is null, sets the current node to null.
*/
template <typename T>
tree<T>::InOrderIterator::InOrderIterator(Node<T> *root) : isBinary(root ? root->maxChilds == 2 : true)
{
    if (root)
    {
        if (isBinary)
        {
            traverse(root);
            current = in_order_queue.empty() ? nullptr : in_order_queue.front();
        }
        else
        {
            nodes.push(root);
            while (!nodes.empty())
            {
                Node<T> *node = nodes.top();
                nodes.pop();
                in_order_queue.push(node);
                for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
                {
                    if (*it)
                    {
                        nodes.push(*it);
                    }
                }
            }
            current = in_order_queue.empty() ? nullptr : in_order_queue.front();
        }
    }
    else
    {
        current = nullptr;
    }
}
// Recursively traverses the tree and splits children by middle index for in-order traversal.
template <typename T>
void tree<T>::InOrderIterator::traverse(Node<T> *node)
{
    if (!node)
        return;

    int total = node->children.size();

    // Traverse the first half of the children
    for (int i = 0; i < total / 2; ++i)
    {
        traverse(node->children[i]);
    }

    // Process the current node
    in_order_queue.push(node);

    // Traverse the second half of the children
    for (int i = total / 2; i < total; ++i)
    {
        traverse(node->children[i]);
    }
}

// Dereference operator that returns the value of the current node or throws a runtime error if the node is null.
template <typename T>
T &tree<T>::InOrderIterator::operator*() const
{
    if (current)
    {
        return current->value;
    }
    else
    {
        throw std::runtime_error("Dereferencing a null pointer");
    }
}
// Pre-increment operator that pops the current node from the in-order queue based on binary or non-binary logic.
template <typename T>
typename tree<T>::InOrderIterator &tree<T>::InOrderIterator::operator++()
{
    if (isBinary)
    {
        if (!in_order_queue.empty())
        {
            in_order_queue.pop();
            current = in_order_queue.empty() ? nullptr : in_order_queue.front();
        }
    }
    else
    {
        if (!in_order_queue.empty())
        {
            in_order_queue.pop();
            current = in_order_queue.empty() ? nullptr : in_order_queue.front();
        }
    }
    return *this;
}
//  Equality operator checking if two iterators are at the same position.
template <typename T>
bool tree<T>::InOrderIterator::operator==(const InOrderIterator &rhs) const
{
    return current == dynamic_cast<const InOrderIterator*>(&rhs)->current;
}
// Inequality operator checking if two iterators are at different positions.
template <typename T>
bool tree<T>::InOrderIterator::operator!=(const InOrderIterator &rhs) const
{
    return current != dynamic_cast<const InOrderIterator*>(&rhs)->current;
}

/**
 * It explicitly instantiates the InOrderIterator class for various types (int, float, double, char, string, Complex).
 * This allows the compiler to generate the necessary code for these specific types.
*/
template class tree<int>::InOrderIterator;
template class tree<float>::InOrderIterator;
template class tree<double>::InOrderIterator;
template class tree<char>::InOrderIterator;
template class tree<string>::InOrderIterator;
template class tree<Complex>::InOrderIterator;

