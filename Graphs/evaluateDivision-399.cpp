#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    double dfs(string current, string target, double value,
               unordered_map<string, vector<pair<string, double>>>& graph,
               unordered_map<string, bool>& visited) {
        
        if (current == target)
            return value;

        visited[current] = true;

        for (auto& [next, weight] : graph[current]) {
            if (!visited[next]) {
                double result = dfs(next, target, value * weight, graph, visited);

                if (result != -1.0)
                    return result;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];

            graph[a].push_back({b, value});
            graph[b].push_back({a, 1.0 / value});
        }

        vector<double> ans;

        for (auto& query : queries) {
            string start = query[0];
            string target = query[1];

            if (!graph.count(start) || !graph.count(target)) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_map<string, bool> visited;

            ans.push_back(dfs(start, target, 1.0, graph, visited));
        }

        return ans;
    }
};