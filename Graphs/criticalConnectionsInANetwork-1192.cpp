#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int timer = 0;

    void dfs(int node, int parent, vector<vector<int>>& adj,
             vector<int>& discovery, vector<int>& low,
             vector<vector<int>>& ans) {
        
        discovery[node] = low[node] = timer++;

        for (int neighbor : adj[node]) {
            if (neighbor == parent)
                continue;

            if (discovery[neighbor] == -1) {
                dfs(neighbor, node, adj, discovery, low, ans);

                low[node] = min(low[node], low[neighbor]);

                if (low[neighbor] > discovery[node])
                    ans.push_back({node, neighbor});
            }
            else {
                low[node] = min(low[node], discovery[neighbor]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections
    ) {
        vector<vector<int>> adj(n);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> discovery(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> ans;

        dfs(0, -1, adj, discovery, low, ans);

        return ans;
    }
};