
#include <iostream>
using namespace std;

// Definition of a Node in a binary tree
struct Node {
    int data; // Data of the node
    Node* left; // Pointer to the left child
    Node* right; // Pointer to the right child

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = nullptr; // Initialize left child as nullptr
        right = nullptr; // Initialize right child as nullptr
    }
};

// Class to represent a binary tree
class BinaryTree {
private:
    Node* root; // Root of the binary tree

public:
    // Constructor to create an empty binary tree
    BinaryTree() {
        root = nullptr; // Initialize root as nullptr
    }

    // Function to insert a new node with given data
    Node* insert(Node* node, int data) {
        // If the tree is empty, return a new node
        if (node == nullptr) {
            return new Node(data);
        }

        // Otherwise, recur down the tree
        if (data < node->data) {
            node->left = insert(node->left, data); // Insert in the left subtree
        } else {
            node->right = insert(node->right, data); // Insert in the right subtree
        }
        return node; // Return the unchanged node pointer
    }

    // Function to perform in-order traversal of the tree
    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left); // Traverse the left subtree
            cout << node->data << " "; // Print the data
            inOrder(node->right); // Traverse the right subtree
        }
    }

    // Function to perform pre-order traversal of the tree
    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " "; // Print the data
            preOrder(node->left); // Traverse the left subtree
            preOrder(node->right); // Traverse the right subtree
        }
    }

    // Function to perform post-order traversal of the tree
    void postOrder(Node* node) {
        if (node != nullptr) {
            postOrder(node->left); // Traverse the left subtree
            postOrder(node->right); // Traverse the right subtree
            cout << node->data << " "; // Print the data
        }
    }

    // Function to initiate insertion from the root
    void insert(int data) {
        root = insert(root, data); // Call the recursive insert function
    }

    // Function to initiate in-order traversal from the root
    void inOrder() {
        cout << "In-order traversal: ";
        inOrder(root); // Call the recursive inOrder function
        cout << endl; // Print a newline
    }

    // Function to initiate pre-order traversal from the root
    void preOrder() {
        cout << "Pre-order traversal: ";
        preOrder(root); // Call the recursive preOrder function
        cout << endl; // Print a newline
    }

    // Function to initiate post-order traversal from the root
    void postOrder() {
        cout << "Post-order traversal: ";
        postOrder(root); // Call the recursive postOrder function
        cout << endl; // Print a newline
    }
};

// Main function to demonstrate Binary Tree Traversal
int main() {
    BinaryTree tree; // Create a BinaryTree object

    // Insert nodes into the binary tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    tree.inOrder(); // Print the in-order traversal of the tree
    tree.preOrder(); // Print the pre-order traversal of the tree
    tree.postOrder(); // Print the post-order traversal of the tree

    return 0; // Indicate that the program ended successfully
}
