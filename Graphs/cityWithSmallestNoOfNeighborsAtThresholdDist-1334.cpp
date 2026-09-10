#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int via = 0; via < n; via++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    dist[u][v] = min(dist[u][v], dist[u][via] + dist[via][v]);
                }
            }
        }

        int city = -1;
        int minCount = INT_MAX;

        for (int u = 0; u < n; u++) {
            int count = 0;

            for (int v = 0; v < n; v++) {
                if (u != v && dist[u][v] <= distanceThreshold)
                    count++;
            }

            if (count <= minCount) {
                minCount = count;
                city = u;
            }
        }

        return city;
    }
};