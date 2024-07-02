/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */
#ifndef tree_HPP
#define tree_HPP

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <SFML/Graphics.hpp>
#include <stdexcept>

#include "Complex.hpp"

using namespace std;

/**
 * @brief A template structure that represents a node in a tree.
 *
 * This structure defines a node in a tree with a generic value type.
 * Each node can have multiple children stored in a vector.
 *
 * @tparam T The type of value stored in the node.
 */

template <typename T>
struct Node
{
    T value;
    std::vector<Node *> children; // A vector that stores pointers to the node's children.
    size_t maxChilds;             // The maximum number of children the node can have.

    /**
     * A counter for the current number of children.
     * This counter helps keep track of the number of children directlyattached to this node.
     */

    size_t c = 0;

    /**
     * Constructs a node with a given value and a default maximum number of children.
     *
     * This constructor initializes a node with the specified value and sets
     * the maximum number of children (`maxChilds`) to a default of 2.
     */

    Node(T val) : value(val), maxChilds(2) {}

    /**
     * Constructs a node with a given value and a specified maximum number of children.
     *
     * @param max The maximum number of children the node can have.
     *
     * This constructor initializes a node with the specified value and the
     * specified maximum number of children (`maxChilds`).
     */

    Node(T val, int max) : value(val), maxChilds(max) {}
};

/**
 * A template class that represents a k-ary tree.
 *
 * This class defines a tree structure where each node can have multiple children.
 * The tree supports operations such as adding a root and deleting the entire tree.
 *
 * @tparam T The type of value stored in the nodes of the tree.
 */

template <typename T>
class tree
{
private:
    Node<T> *root; // A pointer to the root node of the tree.

    /**
     * Recursively deletes all nodes in the tree starting from the given node.
     *
     * This function is a helper method that recursively traverses the tree and
     * deletes all nodes in a post-order traverse.
     *
     * @param node The starting node for deletion.
     */

    void deleteTree(Node<T> *node)
    {
        if (!node)
            return; // Check for null node

        // Recursively delete all children
        for (Node<T> *child : node->children)
        {
            deleteTree(child);
        }

        // Delete the current node
        delete node;
    }

public:
    // Constructs an empty tree with a null root
    tree()
    {
        this->root = nullptr;
    }
    // Destructor that deletes the entire tree.
    ~tree()
    {
        deleteTree(root);
    }

    /**
     * Adds or updates the root node of the tree with a specified value.
     *
     * If the root node does not exist, this function creates a new root node with the given value.
     * If the root node already exists, its value is updated to the given value.
     *
     * @param value The value to store in the root node.
     * @return A pointer to the root node.
     */

    Node<T> *add_root(T value)
    {
        if (!root)
        {
            root = new Node<T>(value);
        }
        else
        {
            root->value = value;
        }
        return root;
    }

    /**
     * Adds or updates the root node of the tree with a specified value and maximum number of children.
     *
     * If the root node does not exist, this function creates a new root node with the given value and maximum number of children.
     * If the root node already exists, its value is updated to the given value.
     *
     * @param value The value to store in the root node.
     * @param max The maximum number of children the root node can have.
     * @return A pointer to the root node.
     */

    Node<T> *add_root(T value, int max)
    {
        if (!root)
        {
            root = new Node<T>(value, max);
        }
        else
        {
            root->value = value;
        }
        return root;
    }

    /**
     * Adds a child to the node.
     *
     * @param child A pointer to the child node to add.
     *
     * Adds the given child node to the children vector if the current number
     * of children (`c`) is less than `maxChilds`.
     */

    void add_sub_node(Node<T> *n, T value)
    {
        if (n)
        {
            if (n->c == n->maxChilds)
            {
                std::ostringstream oss;
                oss << "You have reached the max child size of " << n->maxChilds;
                throw std::runtime_error(oss.str());
            }
            else
            {
                n->children.push_back(new Node<T>(value, root->maxChilds));
                n->c++;
            }
        }
    }
    // Return a pointer to the root node, or nullptr if the tree is empty.
    Node<T> *get_root() const
    {
        if (!root)
        {
            throw std::runtime_error("Tree is empty!");
        }
        return root;
    }
    /**
     * Gets the value stored in the root node of the tree.
     *
     * @return The value stored in the root node.
     * @throws std::runtime_error if the tree is empty (i.e., root is nullptr).
     */
    T get_root_value() const
    {
        if (!root)
        {
            throw std::runtime_error("Tree is empty!");
        }
        return root->value;
    }

    /**
     * Converts the tree into a min-heap and outputs the heap values.
     *
     * This method uses the MinHeapIterator to traverse and print the values
     * of the tree nodes after converting the tree into a min-heap.
     *
     * @param out The output stream to which the heap values are written.
     *            Defaults to std::cout.
     * @throws std::runtime_error if the tree is empty.
     */
    class MinHeapIterator; 
    MinHeapIterator myHeap(ostream &out = std::cout)
    {
        if (!root)
        {
            throw std::runtime_error("Tree is empty!");
        }

        MinHeapIterator it(root);
        MinHeapIterator end(nullptr);

        while (it != end)
        {
            out << *it;
            out << " ";
            ++it;
        }
        return MinHeapIterator(root);
    }

    class DFSIterator
    {
    public:
        DFSIterator(Node<T> *root);                      // Constructor with the root node.
        T &operator*();                                  // Dereference operator.
        DFSIterator &operator++();                       // Pre-increment operator.
        bool operator==(const DFSIterator &rhs) const;   // Equality operator.
        bool operator!=(const DFSIterator &other) const; // Inequality operator.

    private:
        std::stack<Node<T> *> nodes; // Utilized to keep track of nodes for the depth-first search traversal.
        Node<T> *current;
    };

    // Returns iterators for traversing the tree using the DFS method.

    DFSIterator begin_dfs_scan()
    {
        return DFSIterator(root);
    }
    DFSIterator end_dfs_scan()
    {
        return DFSIterator(nullptr);
    }

    // Pre-order iterator
    class PreOrderIterator
    {
    public:
        PreOrderIterator(Node<T> *root);                    // Constructor with the root node.
        void populatepreOrderStack();                       // Utility method to populate the pre-order stack
        T &operator*() const;                               // Const dereference operator.
        PreOrderIterator &operator++();                     // Pre-increment operator.
        bool operator==(const PreOrderIterator &rhs) const; // Equality operator.
        bool operator!=(const PreOrderIterator &rhs) const; // Inequality operator.

    private:
        queue<Node<T> *> pre_order_nodes;
        stack<Node<T> *> nodes;
        Node<T> *current;
        void traverse(Node<T> *node);
    };

    // Returns iterators for traversing the tree using the pre-order method.

    PreOrderIterator begin_pre_order()
    {
        return PreOrderIterator(root);
    }

    PreOrderIterator end_pre_order()
    {
        return PreOrderIterator(nullptr);
    }

    // Post-order iterator
    class PostOrderIterator
    {
    public:
        PostOrderIterator(Node<T> *root);                      // Constructor with the root node.
        void populatePostOrderStack();                         // Utility method to populate the pre-order stack
        T &operator*() const;                                  // Const dereference operator.
        PostOrderIterator &operator++();                       // Pre-increment operator.
        bool operator==(const PostOrderIterator &other) const; // Equality operator.
        bool operator!=(const PostOrderIterator &other) const; // Inequality operator.

    private:
        queue<Node<T> *> post_order_nodes;
        stack<Node<T> *> nodes;
        Node<T> *current;
        void traverse(Node<T> *node);
    };

    // Returns iterators for traversing the tree using the post-order method.

    PostOrderIterator begin_post_order()
    {
        return PostOrderIterator(root);
    }

    PostOrderIterator end_post_order()
    {
        return PostOrderIterator(nullptr);
    }

    // In-order iterator
    class InOrderIterator
    {
    public:
        InOrderIterator(Node<T> *root);                    // Constructor with the root node.
        T &operator*() const;                              // Const dereference operator.
        InOrderIterator &operator++();                     // Pre-increment operator.
        bool operator==(const InOrderIterator &rhs) const; // Equality operator.
        bool operator!=(const InOrderIterator &rhs) const; // Inequality operator.

    private:
        bool isBinary;
        queue<Node<T> *> in_order_queue;
        Node<T> *current;
        stack<Node<T> *> nodes;
        void traverse(Node<T> *node);
    };

    // Returns iterators for traversing the tree using the in-order method.

    InOrderIterator begin_in_order()
    {
        return InOrderIterator(root);
    }

    InOrderIterator end_in_order()
    {
        return InOrderIterator(nullptr);
    }

    // BFS iterator
    class BFSIterator
    {
    public:
        BFSIterator(Node<T> *root);                      // Constructor with the root node.
        T &operator*();                                  // Const dereference operator.
        BFSIterator &operator++();                       // Pre-increment operator.
        bool operator!=(const BFSIterator &other) const; // Equality operator.
        bool operator==(const BFSIterator &rhs) const;   // Inequality operator.

    private:
        std::queue<Node<T> *> nodes;
        Node<T> *current;
    };

    // Returns iterators for traversing the tree using the BFS method.

    BFSIterator begin_bfs_scan()
    {
        return BFSIterator(root);
    }
    BFSIterator end_bfs_scan()
    {
        return BFSIterator(nullptr);
    }

    // MinHeapIterator iterator
    class MinHeapIterator
    {
    public:
        MinHeapIterator(Node<T> *root);                    // Constructor with the root node.
        T &operator*() const;                              // Const dereference operator.
        MinHeapIterator &operator++();                     // Pre-increment operator.
        bool operator==(const MinHeapIterator &rhs) const; // Equality operator.
        bool operator!=(const MinHeapIterator &rhs) const; // Inequality operator.

    private:
        std::vector<Node<T> *> heap;
        queue<Node<T> *> nodesQueue;
        Node<T> *current;
        void buildHeap(int n, int k);
        void heapify(int len, int index, int k);
        int k; // Maximum number of children
    };

    // Returns iterators for traversing the tree using the heap method.

    MinHeapIterator begin_heap()
    {
        return MinHeapIterator(root);
    }
    MinHeapIterator end_heap()
    {
        return MinHeapIterator(nullptr);
    }
};
/**
 * defining the radius of tree nodes,
 * vertical spacing between nodes, and horizontal spacing between nodes, respectively.
 */
const float NODE_RADIUS = 20.0f;
const float VERTICAL_SPACING = 70.0f;
const float HORIZONTAL_SPACING = 70.0f;

/**
 * The TreeGUI class is responsible for rendering a visualization of a k-ary tree on an SFML window,
 * providing a graphical representation of the tree nodes with spacing and styling.
 */

template <typename T>
class TreeGUI
{
public:
    // Constructs a TreeGUI object with the provided k-ary tree and loading the font.
    TreeGUI(tree<T> &Ktree) : Ktree(Ktree)
    {
        if (!font.loadFromFile("JetBrainsMono-SemiBold.ttf"))
        {
            throw std::runtime_error("Failed to load font!");
        }
    }
    // Runs the SFML window loop, initializing the window and handling event polling,
    // drawing the tree, and displaying the window.
    void run()
    {
        sf::RenderWindow window(sf::VideoMode(1280, 720), "K-Ary Tree");

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            drawTree(window, Ktree.get_root(), window.getSize().x / 2, 50, window.getSize().x / 4);
            window.display();
        }
    }

private:
    tree<T> &Ktree;
    sf::Font font;

    /**
     * The method drawTree is used to draw each node of the tree on the SFML window.
     * Each node is represented by a circle shape with text displaying the node's value inside the circle.
     * Parent nodes are connected to their child nodes with lines representing the tree structure.
     */

    void drawTree(sf::RenderWindow &window, Node<T> *node, float x, float y, float horizontalOffset)
    {
        if (!node)
            return;

        drawNode(window, node, x, y);

        float childX = x - (horizontalOffset * (node->children.size() - 1) / 2);
        for (Node<T> *child : node->children)
        {
            if (child)
            {
                drawEdge(window, x, y + NODE_RADIUS, childX, y + VERTICAL_SPACING - NODE_RADIUS);
                drawTree(window, child, childX, y + VERTICAL_SPACING, horizontalOffset * 0.5f);
                childX += horizontalOffset;
            }
        }
    }

    /**
     * Nodes are positioned based on the provided x and y coordinates,
     * with adjustments for horizontal offset and child node spacing to create
     * a visually appealing tree layout.
     */
    void drawNode(sf::RenderWindow &window, Node<T> *node, float x, float y)
    {
        sf::CircleShape circle(NODE_RADIUS);
        circle.setFillColor(sf::Color(250, 250, 210));    // A light yellow color
        circle.setOutlineColor(sf::Color(200, 100, 100)); // A dark red color
        circle.setOutlineThickness(3);
        circle.setPosition(x - NODE_RADIUS, y - NODE_RADIUS);

        window.draw(circle);


        sf::Text text;
        text.setFont(font);
        if constexpr (std::is_same<T, Complex>::value)
            text.setString(node->value.to_string());
        else if constexpr (std::is_same<T, char>::value)
            text.setString(std::string(1, node->value)); // Convert char to std::string
        else
            text.setString(std::to_string(node->value));
            
        text.setCharacterSize(15);
        text.setFillColor(sf::Color::Black);

        // Obtain the bounding box of the text to accurately center it
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        text.setPosition(x, y);

        window.draw(text);
    }
    /**
     * Draws an edge (line) connecting a parent node to a child node in the tree visualization.
     *
     * This function draws a line connecting two points, representing the parent and child nodes.
     * The coordinates of the parent node are specified by (parentX, parentY) and the coordinates
     * of the child node are specified by (childX, childY). The line is drawn in black color.
     */
    void drawEdge(sf::RenderWindow &window, float parentX, float parentY, float childX, float childY)
    {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(parentX, parentY), sf::Color::Black),
            sf::Vertex(sf::Vector2f(childX, childY), sf::Color::Black)};

        window.draw(line, 2, sf::Lines);
    }
};
#endif // tree_HPP
