#include<vector>
using namespace std;

#define ll long long int
#define mod 1000000007
class Solution {
public:
    vector<vector<ll>> dp;
    
    ll WaysToRollTheDiceToGetTarget(int n,int k,int target){

        if(n==0 && target==0) return 1;
        if(n==0 ||target==0 ) return 0;

        if(dp[n][target]!=-1) return dp[n][target];

        ll result=0;
        for(int i=1;i<=k;i++){
            if(target-i <0) break;
            result=(result%mod + (WaysToRollTheDiceToGetTarget(n-1,k,target-i)%mod))%mod;
        }

        return dp[n][target]=result;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(n+1,vector<ll> (target+1,-1));

        return WaysToRollTheDiceToGetTarget(n,k,target);
    }
};