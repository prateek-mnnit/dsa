class Solution {
public:
    int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row == 0 && col == 0){
            return grid[row][col];
        }

        if(dp[row][col] != -1) 
            return dp[row][col];

        int up = INT_MAX;
        int left = INT_MAX;
        if(row-1 >= 0)
            up = grid[row][col] + f(row-1, col, grid,dp);
        if(col-1 >= 0)
            left = grid[row][col] + f(row, col-1, grid,dp);
        return dp[row][col] =  min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));

        return f(m-1,n-1,grid,dp);

    }
};