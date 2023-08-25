#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999

typedef pair<int, int> pii;

void Dijkstra(vector<vector<pii>>& graph, int source, vector<int>& dist) {
    int n = graph.size();
    dist.resize(n, INF);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Skip if already processed
        if (d > dist[u])
            continue;

        // Relaxation step
        for (pii neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<pii>> graph(n);

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight)); // If the graph is undirected
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    vector<int> dist;
    Dijkstra(graph, source, dist);

    cout << "Shortest distances from vertex " << source << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": ";
        if (dist[i] == INF)
            cout << "Not reachable";
        else
            cout << dist[i];
        cout << endl;
    }

    return 0;
}
