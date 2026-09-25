#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;

        int rows =obstacleGrid.size();
        int cols=obstacleGrid[0].size();

        vector<vector<int>> dp(rows,vector<int> (cols,0));
        
        dp[0][0]=1;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 && j==0) continue;

                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                } 

                if(i>0) dp[i][j]+=dp[i-1][j];
                if(j>0) dp[i][j]+=dp[i][j-1];

            }
        }
        return dp[rows-1][cols-1];

        
    }
};