#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjList;

public:
    Graph(int n) : numVertices(n) {
        adjList.resize(numVertices);
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    // Function to perform BFS traversal
    void BFS(int startVertex) {
        std::vector<bool> visited(numVertices, false); // Keep track of visited vertices
        std::queue<int> q; // Queue for BFS traversal

        // Mark the start vertex as visited and enqueue it
        visited[startVertex] = true;
        q.push(startVertex);

        std::cout << "BFS Traversal: ";

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            std::cout << vertex << " ";

            // Enqueue all adjacent vertices of the current vertex that have not been visited
            for (int adjVertex : adjList[vertex]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
            }
        }

        std::cout << std::endl;
    }
};

int main() {
    // Create a graph
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);

    // Perform BFS traversal starting from vertex 0
    graph.BFS(0);

    return 0;
}
