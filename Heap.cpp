/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */
#include "tree.hpp"

/**
 * This class represents an iterator for traversing a tree in a way that maintains a 
 * min-heap ordering based on the node values.
*/

/**
 * Constructs the iterator with the given root node if not null.
 * If the root is provided, it initializes the iterator by traversing the tree, 
 * building a min-heap from the nodes based on the maximum number of children (k), and setting the current node accordingly.
*/
template <typename T>
tree<T>::MinHeapIterator::MinHeapIterator(Node<T> *root) : current(nullptr), k(0) {
    if (root) {
        k = root->maxChilds;
        nodesQueue.push(root);
        while (!nodesQueue.empty()) {
            Node<T> *node = nodesQueue.front();
            nodesQueue.pop();
            heap.push_back(node);
            for (auto child : node->children) {
                if (child) {
                    nodesQueue.push(child);
                }
            }
        }
        buildHeap(heap.size(), k);
        if (!heap.empty()) {
            current = heap[0];
        }
    }
}

//Builds a min-heap from the nodes in the tree using a specified branching factor k.
template <typename T>
void tree<T>::MinHeapIterator::buildHeap(int n, int k) {
    for (int i = (n - 1) / k; i >= 0; i--) {
        heapify(n, i, k);
    }
}
//Maintains the min-heap property by ensuring the node at index is smaller than its 
//children with a maximum of k children.
template <typename T>
void tree<T>::MinHeapIterator::heapify(int len, int index, int k) {
    std::vector<int> child(k + 1);

    while (true) {
        for (int i = 1; i <= k; i++) {
            child[i] = (k * index + i) < len ? (k * index + i) : -1;
        }

        int min_child_index = -1;
        bool min_child_found = false;

        for (int i = 1; i <= k; i++) {
            if (child[i] != -1) {
                if (!min_child_found || heap[child[i]]->value < heap[min_child_index]->value) {
                    min_child_index = child[i];
                    min_child_found = true;
                }
            }
        }

        if (!min_child_found)
            break;

        if (heap[index]->value > heap[min_child_index]->value) {
            std::swap(heap[index], heap[min_child_index]);
        }

        index = min_child_index;
    }
}
//Dereference operator that returns the value of the current node or throws a runtime error if the node is null.
template <typename T>
T &tree<T>::MinHeapIterator::operator*() const {
    if (current) {
        return current->value;
    } else {
        throw std::runtime_error("Dereferencing a null pointer");
    }
}

// Pre-increment operator that updates the iterator by removing the root of the heap 
// and re-heapifying to maintain the min-heap property.
template <typename T>
typename tree<T>::MinHeapIterator &tree<T>::MinHeapIterator::operator++() {
    if (!heap.empty()) {
        std::swap(heap[0], heap.back());
        heap.pop_back();
        if (!heap.empty()) {
            heapify(heap.size(), 0, k);
            current = heap[0];
        } else {
            current = nullptr;
        }
    }
    return *this;
}
// Equality operator checking if two iterators are at the same position.
template <typename T>
bool tree<T>::MinHeapIterator::operator==(const MinHeapIterator &rhs) const {
    return current == rhs.current;
}
// Inequality operator checking if two iterators are at different positions.
template <typename T>
bool tree<T>::MinHeapIterator::operator!=(const MinHeapIterator &rhs) const {
    return !(*this == rhs);
}

// The class is explicitly instantiated for various types (int, float, double, char, string, Complex).
template class tree<int>::MinHeapIterator;
template class tree<float>::MinHeapIterator;
template class tree<double>::MinHeapIterator;
template class tree<char>::MinHeapIterator;
template class tree<string>::MinHeapIterator;
template class tree<Complex>::MinHeapIterator;
