
#include <iostream>
#include <vector>
#include <queue> // Include queue header for BFS
using namespace std;

// Function to perform BFS on a graph represented as an adjacency list
void bfs(int start, vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false); // Track visited nodes
    queue<int> q; // Create a queue for BFS

    visited[start] = true; // Mark the starting node as visited
    q.push(start); // Enqueue the starting node

    cout << "BFS Traversal starting from node " << start << ": ";

    while (!q.empty()) {
        int node = q.front(); // Get the front node of the queue
        cout << node << " "; // Print the node
        q.pop(); // Dequeue the front node

        // Iterate through all adjacent nodes
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) { // If the neighbor hasn't been visited
                visited[neighbor] = true; // Mark it as visited
                q.push(neighbor); // Enqueue the neighbor
            }
        }
    }
    cout << endl; // Newline for better output formatting
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

    int startNode = 0; // Starting node for BFS
    bfs(startNode, graph); // Call BFS function

    return 0; // Indicate that the program ended successfully
}
