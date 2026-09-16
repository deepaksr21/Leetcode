#include <vector>

using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;

        if (rank[pu] < rank[pv])
            swap(pu, pv);

        parent[pv] = pu;

        if (rank[pu] == rank[pv])
            rank[pu]++;

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto& edge : edges) {
            if (!unite(edge[0], edge[1]))
                return edge;
        }

        return {};
    }
};