class Solution {
public:
    int f(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {

        if (obstacleGrid[row][col] == 1)
            return 0;

        if (row == 0 && col == 0)
            return 1;

        if(dp[row][col] != -1)
            return dp[row][col];
        int up = 0;
        int left = 0;

        if (row - 1 >= 0)
            up = f(row - 1, col, obstacleGrid,dp);

        if (col - 1 >= 0)
            left = f(row, col - 1, obstacleGrid,dp);

        return dp[row][col] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return f(m - 1, n - 1, obstacleGrid,dp);
    }
};