#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Structure to represent a node in the Huffman tree
struct Node {
    char data; // Character data
    int freq; // Frequency of the character
    Node* left; // Pointer to the left child
    Node* right; // Pointer to the right child

    // Constructor
    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

// Comparison function to create a min-heap
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // Return true if a's frequency is greater than b's
    }
};

// Function to print the Huffman codes recursively
void printCodes(Node* root, string str) {
    if (!root) return; // Base case

    // If this is a leaf node, print the character and its code
    if (!root->left && !root->right) {
        cout << root->data << ": " << str << endl;
    }

    // Recur for the left and right children
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to build the Huffman tree
void buildHuffmanTree(const unordered_map<char, int>& frequencies) {
    priority_queue<Node*, vector<Node*>, compare> minHeap; // Min-heap priority queue

    // Create a leaf node for each character and add it to the min-heap
    for (auto pair : frequencies) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Iterate until there is more than one node in the min-heap
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); // Get the two nodes with the smallest frequencies
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with these two nodes as children and their frequency as the sum
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Add the new node to the min-heap
        minHeap.push(newNode);
    }

    // The remaining node is the root of the Huffman tree
    Node* root = minHeap.top();
    cout << "Huffman Codes:\n";
    printCodes(root, ""); // Print the codes
}

int main() {
    // Example character frequencies
    unordered_map<char, int> frequencies = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}
    };

    buildHuffmanTree(frequencies); // Build the Huffman tree

    return 0; // Indicate that the program ended successfully
}

