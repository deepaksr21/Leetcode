#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <climits>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int, pair<int,int>> pp;

    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        int dir[4][2] = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };

        priority_queue<
            pp,
            vector<pp>,
            greater<pp>
        > pq;

        vector<vector<int>> dist(
            rows,
            vector<int>(cols, INT_MAX)
        );

        dist[0][0] = 0;

        pq.push({0,{0,0}});

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int currWt = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            if(dist[i][j] < currWt)
                continue;

            for(int d = 0; d < 4; d++) {

                int dx = i + dir[d][0];
                int dy = j + dir[d][1];

                if(dx < 0 || dy < 0 ||
                   dx >= rows || dy >= cols)
                    continue;

                int edgeWt = abs(
                    heights[i][j] - heights[dx][dy]
                );

                int newEffort = max(currWt, edgeWt);

                if(dist[dx][dy] > newEffort) {

                    dist[dx][dy] = newEffort;

                    pq.push({
                        newEffort,
                        {dx,dy}
                    });
                }
            }
        }

        return dist[rows-1][cols-1];
    }
};