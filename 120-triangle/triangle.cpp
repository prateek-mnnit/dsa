class Solution {
public:
    int f(int row, int col, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(row == n-1){
            return triangle[row][col];
        }
        if(dp[row][col] != INT_MAX)
            return dp[row][col];

        int first = INT_MAX;
        int second = INT_MAX;
        first = triangle[row][col] + f(row+1,col,n,triangle,dp);
        if(col+1 < triangle[row+1].size())
            second = triangle[row][col] + f(row+1,col+1,n,triangle,dp);

        return dp[row][col] = min(first , second);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m,INT_MAX));
        return f(0,0,n,triangle,dp);
    }
};


// class Solution {
// public:
//     int f(int row, int col, int n, vector<vector<int>>& triangle,
//           vector<vector<int>>& dp) {

//         if(row == n - 1)
//             return triangle[row][col];

//         if(dp[row][col] != -1)
//             return dp[row][col];

//         int first = triangle[row][col] +
//                     f(row + 1, col, n, triangle, dp);

//         int second = triangle[row][col] +
//                      f(row + 1, col + 1, n, triangle, dp);

//         return dp[row][col] = min(first, second);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {

//         int n = triangle.size();

//         vector<vector<int>> dp(n, vector<int>(n, -1));

//         return f(0, 0, n, triangle, dp);
//     }
// };