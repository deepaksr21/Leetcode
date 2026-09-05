#include<vector>
using namespace std;
class Solution {
public:
    void dfs(int i,vector<bool>& visited,vector<vector<int>>& graph){
        visited[i]=true;

        for(int neighbour:graph[i]){
            if(!visited[neighbour]){
                dfs(neighbour,visited,graph);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>> graph(stones.size());

        //constructing the graph
        for(int i=0;i<stones.size()-1;i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1] ){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        //finding the connected components
        vector<bool> visited(stones.size(),false);
        int cc=0;
        for(int i=0;i<stones.size();i++){
            if(!visited[i]){
                cc++;
                cout<<cc<<" ";
                dfs(i,visited,graph);

            }

        }
        return stones.size()-cc;
        
    }
};