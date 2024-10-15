
#include <iostream>
#include <vector>
#include <queue> // For queue
using namespace std;

// Function to perform BFS on a graph
void BFS(int start, const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false); // Track visited vertices
    queue<int> q; // Create a queue for BFS

    // Start with the initial vertex
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front(); // Get the front vertex
        cout << vertex << " "; // Process the vertex
        q.pop(); // Remove the vertex from the queue

        // Visit all adjacent vertices
        for (int adjacent : graph[vertex]) {
            if (!visited[adjacent]) { // If not visited
                visited[adjacent] = true; // Mark as visited
                q.push(adjacent); // Add to the queue
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},     // Neighbors of vertex 0
        {0, 3, 4},  // Neighbors of vertex 1
        {0, 4},     // Neighbors of vertex 2
        {1},        // Neighbors of vertex 3
        {1, 2}      // Neighbors of vertex 4
    };

    cout << "Breadth-First Search starting from vertex 0:\n";
    BFS(0, graph); // Call BFS starting from vertex 0

    return 0; // Indicate that the program ended successfully
}
