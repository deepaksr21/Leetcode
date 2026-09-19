#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    unordered_map<string, map<string, int>> graph;
    vector<string> ans;

    void dfs(string airport) {
        while (!graph[airport].empty()) {
            auto it = graph[airport].begin();
            string next = it->first;

            if (--it->second == 0)
                graph[airport].erase(it);

            dfs(next);
        }

        ans.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets)
            graph[ticket[0]][ticket[1]]++;

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};