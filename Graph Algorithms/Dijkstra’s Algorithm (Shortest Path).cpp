
#include <iostream>
#include <vector>
#include <queue> // Include queue header for the priority queue
#include <climits> // Include for INT_MAX
using namespace std;

// Function to perform Dijkstra's Algorithm
void dijkstra(int start, vector<vector<pair<int, int>>>& graph) {
    int V = graph.size(); // Number of vertices in the graph
    vector<int> dist(V, INT_MAX); // Distance from the start node to each node
    dist[start] = 0; // Distance to the starting node is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue
    pq.push({0, start}); // Push the starting node into the queue

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the smallest distance
        pq.pop(); // Remove it from the queue

        // Iterate through all adjacent nodes
        for (auto& edge : graph[u]) {
            int v = edge.first; // Neighbor vertex
            int weight = edge.second; // Weight of the edge

            // If a shorter path to v is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight; // Update the shortest distance
                pq.push({dist[v], v}); // Push the updated distance into the priority queue
            }
        }
    }

    // Print the shortest distances from the start node to all other nodes
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << ": INF" << endl; // Node is unreachable
        } else {
            cout << "Node " << i << ": " << dist[i] << endl; // Print the distance
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 1}},    // Edges for node 0
        {{0, 4}, {2, 2}, {3, 1}}, // Edges for node 1
        {{0, 1}, {1, 2}, {3, 5}}, // Edges for node 2
        {{1, 1}, {2, 5}}     // Edges for node 3
    };

    int startNode = 0; // Starting node for Dijkstra's Algorithm
    dijkstra(startNode, graph); // Call Dijkstra's function

    return 0; // Indicate that the program ended successfully
}
