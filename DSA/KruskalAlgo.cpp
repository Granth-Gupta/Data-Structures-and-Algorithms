#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Class to represent an edge in the graph
class Edge {
public:
    int src, dest, weight;
};

// Class to represent a disjoint-set data structure
class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootU] = rootV;
            rank[rootV]++;
        }
    }
};

// Comparator function to sort edges by their weights
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
vector<Edge> kruskalsAlgorithm(vector<Edge>& edges, int n) {
    vector<Edge> result;
    DisjointSet ds(n);
    sort(edges.begin(), edges.end(), compareEdges);
    for (const Edge& edge : edges) {
        int rootSrc = ds.find(edge.src);
        int rootDest = ds.find(edge.dest);
        if (rootSrc != rootDest) {
            result.push_back(edge);
            ds.unionSet(rootSrc, rootDest);
        }
    }
    return result;
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    vector<Edge> edges(m);
    cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    int sum = 0;
    vector<Edge> minimumSpanningTree = kruskalsAlgorithm(edges, n);
    cout << "Edges in the minimum spanning tree:\n";
    for (const Edge& edge : minimumSpanningTree) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        sum+= edge.weight;
    }
    cout<<"Minimum weight is: "<<sum<<endl;
    return 0;
}
