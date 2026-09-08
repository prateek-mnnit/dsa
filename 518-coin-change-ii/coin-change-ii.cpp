class Solution {
public:
    int f(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (amount % coins[0] == 0) {
                return 1;
            } else
                return 0;
        }
        if (amount == 0)
            return 1;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int notTake = f(idx - 1, amount, coins, dp);
        int take = 0;
        if (amount >= coins[idx])
            take = f(idx, amount - coins[idx], coins, dp);

        return dp[idx][amount] = take + notTake;
    }

    // int tabulation(int n, int amount, vector<int>& coins) {
    //     vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

    //     for (int i = 0; i <= amount; i++) {
    //         if (i % coins[0] == 0) {
    //             dp[0][i] = 1;
    //         }
    //     }

    //     for (int idx = 1; idx < n; idx++) {
    //         for (int target = 0; target <= amount; target++) {
    //             long long notTake = dp[idx - 1][target];
    //             long long take = 0;
    //             if (target >= coins[idx])
    //                 take = dp[idx][target - coins[idx]];

    //             dp[idx][target] = take + notTake;
    //         }
    //     }
    //     return (int)dp[n - 1][amount];
    // }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
        // return tabulation(n, amount, coins);
    }
};