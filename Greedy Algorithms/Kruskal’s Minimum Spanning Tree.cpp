#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

// Structure to represent an edge
struct Edge {
    int source; // Source vertex
    int destination; // Destination vertex
    int weight; // Weight of the edge
};

// Structure to represent a disjoint set (for union-find)
struct DisjointSet {
    vector<int> parent, rank;

    // Constructor to initialize the disjoint set
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is its own parent initially
        }
    }

    // Find the representative of the set
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    // Union of two sets
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Function to perform Kruskal's algorithm
void kruskalMST(const vector<Edge>& edges, int vertices) {
    DisjointSet ds(vertices); // Create a disjoint set for vertices
    vector<Edge> result; // To store the resultant MST
    int totalWeight = 0; // To store total weight of the MST

    // Sort edges based on their weights
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    // Iterate through the sorted edges
    for (const Edge& edge : sortedEdges) {
        int u = edge.source;
        int v = edge.destination;

        // If the current edge does not form a cycle
        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v); // Include this edge in the MST
            result.push_back(edge); // Add edge to the result
            totalWeight += edge.weight; // Add to total weight
        }
    }

    // Output the resultant MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const Edge& edge : result) {
        cout << edge.source << " -- " << edge.destination << " : " << edge.weight << endl;
    }
    cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << endl;
}

int main() {
    // Example edges (source, destination, weight)
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int vertices = 4; // Number of vertices
    kruskalMST(edges, vertices); // Call Kruskal's algorithm

    return 0; // Indicate that the program ended successfully
}

