#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxPossibleLoot(int i,vector<int>& nums, vector<int>& dp){
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i],nums[i+1]);
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i] + maxPossibleLoot(i+2,nums,dp), 0 + maxPossibleLoot(i+1,nums,dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);

        return maxPossibleLoot(0,nums,dp);
        
    }
};