#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
class Solution { 
public: 
    int bfs(int i, vector<vector<int>>& graph,int n, vector<int>& component){ 
        int minCycle=INT_MAX;// to find the minimum cycle from the cycles which are starting from node i 
        queue<int> q; 
        int csize=component.size(); 
        //vector<int> visited(csize,false); 
        vector<int> parent(n,-1); // we can use this to store parent  
        vector<int> dist(n,-1); 
        dist[i]=0; 
        q.push(i); 
        parent[i]=i;// val doesnt matter here as it is the src node  
        while(!q.empty()){ 
            int curr=q.front(); 
            q.pop(); 
            for(auto neighbour:graph[curr]){ 
                if(dist[neighbour]!=-1 and parent[curr]!=neighbour){ 
                    int cycleLength=dist[neighbour]+dist[curr]+1; 
                    minCycle=min(cycleLength,minCycle); 
 
                } 
                if(dist[neighbour]==-1){ 
                    parent[neighbour]=curr; 
                    q.push(neighbour); 
                    dist[neighbour]=dist[curr]+1; 
                } 
            } 
        } 
        return (minCycle==INT_MAX) ? -1 : minCycle; 
 
 
    } 
    int findShortestCycle(int n, vector<vector<int>>& edges) { 
        vector<vector<int>> graph(n); 
        for(auto edge:edges){ 
            int u=edge[0]; 
            int v=edge[1]; 
            graph[u].push_back(v); 
            graph[v].push_back(u); 
        } 
 
        int ans=INT_MAX; 
        vector<int> visited(n,false); 
        for(int i=0;i<n;i++){ 
            if(visited[i]) continue; 
 
            vector<int> component; 
            queue<int> q; 
            q.push(i); 
            visited[i]=true; 
            component.push_back(i); 
            while(!q.empty()){ 
                int curr=q.front(); 
                q.pop(); 
                for(auto neighbour: graph[curr]){ 
                    if(!visited[neighbour]){ 
                        visited[neighbour]=true; 
                        component.push_back(neighbour); 
                        q.push(neighbour); 
                    } 
                } 
 
            } 
            int shortestCycleofCompo=INT_MAX; 
            for(auto node:component){ 
                int cycle=bfs(node,graph,n,component); 
                if(cycle!=-1){ 
                    shortestCycleofCompo=min(shortestCycleofCompo,cycle); 
                } 
            } 
            if(shortestCycleofCompo!=INT_MAX){ 
                ans=min(ans,shortestCycleofCompo); 
            } 
 
 
 
        } 
        return (ans==INT_MAX) ? -1 : ans; 
         
    } 
};