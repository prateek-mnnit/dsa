class Solution {
public:
    bool f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0)
            return true;
        
        if(idx == 0)
            return nums[0] == target;
        
        if(dp[idx][target] != -1)
            return dp[idx][target];

        if(f(idx-1,target,nums,dp)) return dp[idx][target] = true;

        if(nums[idx] <= target){
            if(f(idx-1,target-nums[idx],nums,dp)) return dp[idx][target] = true;
        }

        return dp[idx][target] = false;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }    
        if(sum%2 != 0)
            return false;
        
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,nums,dp);
    }
};