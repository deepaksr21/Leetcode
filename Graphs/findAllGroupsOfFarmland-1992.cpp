#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& land,int i,int j,int& r1,int& c1,int& r2,int& c2){
        // if we are outside the land vector or land[i][j]==0 (forest land) then return

        if(i<0 ||j<0 || i>=land.size() || j>=land[0].size() || land[i][j]==0) return;

        land[i][j]=0;// marked visited

        r1=min(r1,i);
        c1=min(c1,j);
        r2=max(r2,i);
        c2=max(c2,j);
        int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

        //applying dfs to the neighbours of land[i][j] (land area)
        for(int d=0;d<4;d++){
            int dx=i+dir[d][0];
            int dy=j+dir[d][1];
            dfs(land,dx,dy,r1,c1,r2,c2);
        }


    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                
                if(land[i][j]==1){
                    vector<int> v;

                    int r1,c1,r2,c2;
                    r1=c1=INT_MAX;
                    r2=c2=INT_MIN;
                    
                    dfs(land,i,j,r1,c1,r2,c2);
                    v.insert(v.end(),{r1,c1,r2,c2});
                    ans.push_back(v);
                }
            }
        }
        return ans;
        
    }
};
