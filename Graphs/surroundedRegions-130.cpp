#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int rows=board.size();
        int cols=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 || j==0 || i==rows-1 || j==cols-1){
                    if(board[i][j]=='O') {
                        q.push({i,j});
                        board[i][j]='1';
                    }
                }
            } 
        }      
        int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int i=curr.first;
            int j=curr.second;
            
            for(int d=0;d<4;d++){
                int nr=i+dir[d][0];
                int nc=j+dir[d][1];

                if(nr<0 || nc<0 || nr>=rows || nc>=cols) continue;

                if(board[nr][nc]=='O'){
                    board[nr][nc]='1';
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
               if(board[i][j]=='1') board[i][j]='O';
               else board[i][j]='X';
            }
        }

        return;
        
        
        }
    
};