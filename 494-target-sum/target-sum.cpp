class Solution {
public:
    int f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp,int sum){
        if(target > sum || target < -sum)
            return 0;
        if(idx == 0){
            int ways = 0;
            if(target - nums[0] == 0)
                ways++;
            if(target + nums[0] == 0)
                ways++;
            return ways;
        }
        if(dp[idx][sum + target] != -1) return dp[idx][sum + target];

        int negative = f(idx-1,target-nums[idx],nums,dp,sum);
        int positive = f(idx-1,target+nums[idx],nums,dp,sum);

        return dp[idx][sum + target] = negative + positive;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(target > sum || target < -sum)
            return 0;
        vector<vector<int>> dp(n,vector<int>(2*sum + 1,-1));
        return f(n-1,target,nums,dp,sum);
    }
};