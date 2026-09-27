
#include<vector>
using namespace std;

class Solution {
public:
    #define mod 1000000007
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int> (target+1,0));

        dp[0][0]=1;    //n==0 and target==0

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){

                for(int v=1;v<=k;v++){
                    if(j-v<0) break;
                    dp[i][j]=(dp[i][j]%mod+dp[i-1][j-v]%mod)%mod;
                }

            }
        }
        return dp[n][target];
        
    }
};