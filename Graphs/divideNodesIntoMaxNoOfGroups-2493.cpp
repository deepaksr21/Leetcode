#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int bfs(int i,vector<vector<int>>& graph,int& n){
        vector<int> group(n+1,-1);
        queue<int> q;
        q.push(i);
        group[i]=1;
        int totalgrps=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto neighbour : graph[curr]){
                if(group[neighbour]==-1){
                    group[neighbour]=group[curr]+1;
                    totalgrps=max(totalgrps,group[neighbour]);
                    q.push(neighbour);
                }
                else if((abs(group[neighbour]-group[curr]))!=1) return -1;
            }
        }
        return totalgrps;

    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // step1 -> creating adjacency list representaion of graph from edge list
        vector<vector<int>> graph(n+1);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // step2 -> exploring all the components of the graphs one by one
        vector<bool> visited(n+1,false);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(visited[i]) continue;
            vector<int> component;
            queue<int> q;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                
                component.push_back(curr);
                for(auto neighbour :graph[curr]){
                    if(!visited[neighbour]){
                        visited[neighbour]=true;
                        q.push(neighbour);
                    }
                }
            }
            int maxGrps=1;
            // step3 -> finding maximum groups which can be possible in the component by explorig each node as src node one by one to start bfs
            for(int i=0;i<component.size();i++){
                int grps=bfs(component[i],graph,n);
                if(grps==-1) return -1;
                maxGrps=max(maxGrps,grps);
            }
            // adding maximum grps from all the components of the graph
            ans+=maxGrps;
        } 
        return ans;
    }
};