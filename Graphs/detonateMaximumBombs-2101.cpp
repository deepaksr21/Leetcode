#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    typedef long long int ll;
    void dfs(int i,vector<bool>& visited,vector<vector<ll>>& graph,int& count){
        count++;
        visited[i]=true;
        for(int neighbour : graph[i]){
            if(!visited[neighbour]) dfs(neighbour,visited,graph,count);

        }

    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int v=bombs.size();// no of vertices in the graph
        vector<vector<ll>> graph(v);
        //Building the graph
        for(int i=0;i<v;i++){
            ll x1=bombs[i][0];
            ll y1=bombs[i][1];
            ll r1=bombs[i][2];
            for(int j=0;j<v;j++){
                if(i==j) continue;
                ll x2=bombs[j][0];
                ll y2=bombs[j][1];

                ll dx=x1-x2;
                ll dy=y1-y2;
                if((dx*dx)+(dy*dy)<=(r1*r1)){
                    graph[i].push_back(j);
                }

            }
        }
        int ans=0;
        for(int i=0;i<v;i++){
            vector<bool> visited(v,false);
            int count=0;
            dfs(i,visited,graph,count);
            ans=max(ans,count);

        
        }
        return ans;
    }
};