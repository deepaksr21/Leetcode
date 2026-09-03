#include<vector>
using namespace std;
class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;

        for (int neighbour = 0; neighbour < isConnected.size(); neighbour++) {
            if (isConnected[city][neighbour] == 1 && !visited[neighbour]) {
                dfs(neighbour, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);

        int provinces = 0;

        for (int city = 0; city < n; city++) {
            if (!visited[city]) {
                provinces++;
                dfs(city, isConnected, visited);
            }
        }

        return provinces;
    }
};