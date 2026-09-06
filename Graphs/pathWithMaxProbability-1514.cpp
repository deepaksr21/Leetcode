#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int, double>>> graph(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }

        vector<double> probability(n, 0.0);
        probability[start_node] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            if(curr.second == end_node) return curr.first;
            if(curr.first < probability[curr.second]) continue;

            for(auto neighbour : graph[curr.second]) {

                int nextNode = neighbour.first;
                double edgeProb = neighbour.second;

                double newProb = curr.first * edgeProb;

                if(newProb > probability[nextNode]) {
                    probability[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }

        return 0;
    }
};