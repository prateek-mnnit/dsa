class Solution {
public:
    int f(int idx, int start, vector<int>& nums, vector<int>& dp) {
        if (idx < start)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int rob = nums[idx] + f(idx - 2, start, nums, dp);
        int skip = f(idx - 1, start, nums, dp);

        return dp[idx] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // Don't rob last: [0 ... n-2]
        int case1 = f(n - 2, 0, nums, dp1);

        // Don't rob first: [1 ... n-1]
        int case2 = f(n - 1, 1, nums, dp2);

        return max(case1, case2);
    }
};