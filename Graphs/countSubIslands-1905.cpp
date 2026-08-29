#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    bool dfs(int i, int j, vector<vector<int>>& grid1,vector<vector<int>>& grid2,int& rows, int& cols) {

        // Out of bounds
        if(i < 0 || j < 0 || i >= rows || j >= cols)
            return true;

        // Water or already visited
        if(grid2[i][j] == 0)
            return true;

        // Marking visited
        grid2[i][j] = 0;

        // Checking current cell in grid1 whether it is 1 or not
        // grid2[i][j]=1 ->valid , grid[i][j]=0 ->invalid
        bool valid = (grid1[i][j] == 1);

        int dir[4][2] = {
            {0,1},
            {-1,0},
            {0,-1},
            {1,0}
        };

        for(int d = 0; d < 4; d++) {

            int nx = i + dir[d][0];
            int ny = j + dir[d][1];

            bool result = dfs(nx, ny, grid1, grid2, rows, cols);

            valid = valid && result;
        }

        return valid;
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {

        int rows = grid1.size();
        int cols = grid1[0].size();

        int cc = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid2[i][j] == 1) {

                    if(dfs(i, j, grid1, grid2, rows, cols))
                        cc++;
                }
            }
        }

        return cc;
    }
};