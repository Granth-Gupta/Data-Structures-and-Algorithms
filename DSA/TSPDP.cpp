#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int tspDP(const std::vector<std::vector<int>>& graph, int mask, int pos, std::vector<std::vector<int>>& dp) {
    int n = graph.size();

    if (mask == (1 << n) - 1) {
        return graph[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int minCost = INF;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newMask = mask | (1 << city);
            int cost = graph[pos][city] + tspDP(graph, newMask, city, dp);
            minCost = std::min(minCost, cost);
        }
    }

    dp[mask][pos] = minCost;

    return minCost;
}

int solveTSP(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();

    std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n, -1));

    int minCost = tspDP(graph, 1, 0, dp);

    return minCost;
}

int main() {
    int n;
    std::cout << "Enter the number of cities: ";
    std::cin >> n;

    std::vector<std::vector<int>> graph(n, std::vector<int>(n));

    std::cout << "Enter the cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }

    int minCost = solveTSP(graph);

    std::cout << "Minimum cost of the TSP tour: " << minCost << std::endl;

    return 0;
}
