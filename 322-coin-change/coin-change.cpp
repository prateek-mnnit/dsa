class Solution {
public:
    int f(int idx, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(idx == 0){
            if(target % coins[0] == 0)
                return target/coins[0];
            else
                return 1e9;
        }
        if(target <= 0)
            return 0;

        if(dp[idx][target] != -1)
            return dp[idx][target];
        
        int not_take = 0 + f(idx-1,target,coins,dp);
        int take = INT_MAX;

        if(target >= coins[idx]){
            take = 1 + f(idx,target-coins[idx],coins,dp);
        }

        return dp[idx][target] = min(take,not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,amount,coins,dp);
        if(ans >=1e9)
            return -1;
        else return ans;
    }
};



