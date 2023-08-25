#include <iostream>
#include <vector>

using namespace std;

#define INF 999999

struct Edge {
    int source;
    int destination;
    int weight;
};

void BellmanFord(vector<Edge>& edges, int numVertices, int source) {
    vector<int> dist(numVertices, INF);
    dist[source] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < numVertices - 1; ++i) {
        for (const Edge& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const Edge& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << "Negative-weight cycle detected!\n";
            return;
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from vertex " << source << ":" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        if (dist[i] == INF)
            cout << "Not reachable";
        else
            cout << dist[i];
        cout << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<Edge> edges(numEdges);
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    BellmanFord(edges, numVertices, source);

    return 0;
}
