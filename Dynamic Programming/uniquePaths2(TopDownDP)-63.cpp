#include<vector>
using namespcae std;

class Solution {
public:

    int possibleWays(int cr,int er,int cc,int ec,vector<vector<int>>& dp, vector<vector<int>>& grid){
        if( cr>er || cc>ec || grid[cr][cc]==1) return 0;
        if(cr==er && cc==ec) return 1;
        if(dp[cr][cc]!=-1) return dp[cr][cc];
        return dp[cr][cc]=possibleWays(cr+1,er,cc,ec,dp,grid) + possibleWays(cr,er,cc+1,ec,dp,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows=obstacleGrid.size();
        int cols=obstacleGrid[0].size();
        vector<vector<int>> dp(rows,vector<int> (cols,-1));
        return possibleWays(0,rows-1,0,cols-1,dp,obstacleGrid);
        
    }
};