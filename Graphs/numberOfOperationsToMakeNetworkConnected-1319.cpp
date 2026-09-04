#include<vector>
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

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }

        return true;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int extra = 0;
        int components = n;

        for (auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];

            if (unite(u, v)) {
                components--;
            }
            else {
                extra++;
            }
        }

        if (extra >= components - 1)
            return components - 1;

        return -1;
    }
};