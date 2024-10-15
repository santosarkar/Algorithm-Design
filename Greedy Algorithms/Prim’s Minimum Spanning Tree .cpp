
#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
#include <utility> // For pair
using namespace std;

// Function to find the vertex with the minimum key value
int minKey(const vector<int>& key, const vector<bool>& mstSet, int vertices) {
    int min = INT_MAX, minIndex;

    // Iterate through all vertices to find the minimum key value
    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v]; // Update minimum
            minIndex = v; // Update the index of the minimum key vertex
        }
    }
    return minIndex; // Return the index of the vertex with the minimum key value
}

// Function to perform Prim's algorithm
void primMST(const vector<vector<int>>& graph, int vertices) {
    vector<int> parent(vertices); // To store the constructed MST
    vector<int> key(vertices, INT_MAX); // Key values used to pick the minimum weight edge
    vector<bool> mstSet(vertices, false); // To keep track of vertices included in the MST

    key[0] = 0; // Starting with the first vertex (arbitrarily chosen)
    parent[0] = -1; // First node is always the root

    // The MST will have vertices number - 1 edges
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices); // Get the vertex with the minimum key value
        mstSet[u] = true; // Include this vertex in the MST

        // Update the key value and parent index of the adjacent vertices
        for (int v = 0; v < vertices; v++) {
            // Update key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u; // Update the parent of the vertex
                key[v] = graph[u][v]; // Update the key value
            }
        }
    }

    // Print the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < vertices; i++) {
        cout << parent[i] << " -- " << i << " \t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int vertices = 5; // Number of vertices in the graph
    primMST(graph, vertices); // Call Prim's algorithm

    return 0; // Indicate that the program ended successfully
}
