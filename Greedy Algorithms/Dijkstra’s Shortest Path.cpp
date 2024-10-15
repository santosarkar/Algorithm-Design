
#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;

// Structure to represent a graph edge
struct Edge {
    int destination; // Destination vertex
    int weight; // Weight of the edge
};

// Function to perform Dijkstra's algorithm
void dijkstra(int source, const vector<vector<Edge>>& graph, vector<int>& distances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue
    distances[source] = 0; // Distance from source to itself is 0
    pq.push({0, source}); // Push the source with distance 0

    while (!pq.empty()) {
        int currentDistance = pq.top().first; // Get the smallest distance
        int currentNode = pq.top().second; // Get the current node
        pq.pop(); // Remove the current node from the priority queue

        // If the distance is greater than the recorded distance, skip processing
        if (currentDistance > distances[currentNode]) {
            continue;
        }

        // Iterate through all the edges of the current node
        for (const Edge& edge : graph[currentNode]) {
            int newDistance = currentDistance + edge.weight; // Calculate new distance

            // If a shorter path to the destination is found
            if (newDistance < distances[edge.destination]) {
                distances[edge.destination] = newDistance; // Update the distance
                pq.push({newDistance, edge.destination}); // Push the new distance to the queue
            }
        }
    }
}

int main() {
    int vertices = 5; // Number of vertices
    vector<vector<Edge>> graph(vertices); // Adjacency list representation of the graph

    // Adding edges to the graph (source, destination, weight)
    graph[0].push_back({1, 10});
    graph[0].push_back({2, 3});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 2});
    graph[2].push_back({1, 4});
    graph[2].push_back({3, 8});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 7});
    graph[4].push_back({3, 9});

    vector<int> distances(vertices, INT_MAX); // Initialize distances with infinity
    int source = 0; // Source vertex

    dijkstra(source, graph, distances); // Call Dijkstra's algorithm

    // Print the shortest distances from the source
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": " << (distances[i] == INT_MAX ? "INF" : to_string(distances[i])) << endl;
    }

    return 0; // Indicate that the program ended successfully
}
