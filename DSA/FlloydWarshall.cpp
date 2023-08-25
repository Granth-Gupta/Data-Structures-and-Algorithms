#include <iostream>
#include <vector>

#define INF 99999

void floydWarshall(std::vector<std::vector<int>>& graph) {
    int V = graph.size();

    // Create a copy of the input graph
    std::vector<std::vector<int>> dist = graph;

    // Perform the Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is an intermediate vertex on the shortest path from i to j,
                // update the distance
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances between all pairs of vertices
    std::cout << "All-Pairs Shortest Paths:" << std::endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                std::cout << "INF ";
            } else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // Create a weighted directed graph
    std::vector<std::vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    // Find the shortest paths between all pairs of vertices
    floydWarshall(graph);

    return 0;
}
