#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] == 1)
            return false;

        if (state[node] == 2)
            return true;

        state[node] = 1;

        for (int next : graph[node]) {
            if (!dfs(next, graph, state))
                return false;
        }

        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state))
                ans.push_back(i);
        }

        return ans;
    }
};