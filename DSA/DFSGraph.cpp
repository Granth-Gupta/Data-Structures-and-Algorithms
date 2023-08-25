#include <iostream>
#include <vector>

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

    // Recursive function for DFS traversal
    void DFSUtil(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";

        // Recur for all adjacent vertices of the current vertex
        for (int adjVertex : adjList[vertex]) {
            if (!visited[adjVertex]) {
                DFSUtil(adjVertex, visited);
            }
        }
    }

    // Function to perform DFS traversal
    void DFS(int startVertex) {
        std::vector<bool> visited(numVertices, false); // Keep track of visited vertices
        std::cout << "DFS Traversal: ";
        DFSUtil(startVertex, visited);
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

    // Perform DFS traversal starting from vertex 0
    graph.DFS(0);

    return 0;
}
