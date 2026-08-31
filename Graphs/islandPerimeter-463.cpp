#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int& rows,int& cols){
        if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j]==0) return 1;
        if(grid[i][j]==-1) return 0;// if the cell is already visited
         
        int perimeter=0;

        // marking visited cell as -1
        grid[i][j]=-1;// cant mark visited by 0 as we are using 0 to detect boundary

        int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        for(int d=0;d<4;d++){
            int dx=i+dir[d][0];
            int dy=j+dir[d][1];

            perimeter+=dfs(grid,dx,dy,rows,cols);
        }
        return perimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    return dfs(grid,i,j,rows,cols);
                }
            }
        }
        return 0;
        
    }
};