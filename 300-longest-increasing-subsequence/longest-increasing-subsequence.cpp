class Solution {
public:
    int f(int idx,int prev,int n,vector<int>& nums,vector<vector<int>>& dp){
        if(idx == n)
            return 0;

        if(dp[idx][prev+1] != -1)
            return dp[idx][prev+1];
        int not_take = f(idx+1,prev,n,nums,dp);
        int take = 0;
        if(prev == -1 || nums[idx]>nums[prev]){
            take = 1 + f(idx+1,idx,n,nums,dp);
        }
        return dp[idx][prev+1] = max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,-1,n,nums,dp);
    }
};