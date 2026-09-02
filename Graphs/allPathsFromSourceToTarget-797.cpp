#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int src,int& dest,vector<int>& path,vector<vector<int>>& graph){
        if(src==dest){
            path.push_back(src);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(src);
        for(auto neighbour: graph[src]){
            dfs(neighbour,dest,path,graph);

        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src=0;
        int dest=graph.size()-1;

        vector<int> path;
        dfs(src,dest,path,graph);
        return ans;
        
    }
};