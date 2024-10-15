
#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS recursively
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true; // Mark the current node as visited
    cout << node << " ";  // Print the current node

    // Recursively visit all the adjacent nodes
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) { // If the neighbor hasn't been visited
            dfs(neighbor, graph, visited); // Recursively call DFS for the neighbor
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},    // Edges for node 0
        {0, 3, 4}, // Edges for node 1
        {0, 4},    // Edges for node 2
        {1},       // Edges for node 3
        {1, 2}     // Edges for node 4
    };

    int startNode = 0; // Starting node for DFS
    vector<bool> visited(graph.size(), false); // Create a visited array initialized to false

    cout << "DFS Traversal starting from node " << startNode << ": ";
    dfs(startNode, graph, visited); // Call DFS function

    cout << endl; // Newline for better output formatting
    return 0; // Indicate that the program ended successfully
}
