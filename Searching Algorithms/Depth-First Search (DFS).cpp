#include <iostream>
#include <vector>
using namespace std;

// Recursive function to perform DFS
void DFS(int vertex, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[vertex] = true; // Mark the vertex as visited
    cout << vertex << " "; // Process the vertex

    // Visit all adjacent vertices
    for (int adjacent : graph[vertex]) {
        if (!visited[adjacent]) { // If not visited
            DFS(adjacent, visited, graph); // Recursive call
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

    vector<bool> visited(graph.size(), false); // Track visited vertices

    cout << "Depth-First Search starting from vertex 0:\n";
    DFS(0, visited, graph); // Call DFS starting from vertex 0

    return 0; // Indicate that the program ended successfully
}

