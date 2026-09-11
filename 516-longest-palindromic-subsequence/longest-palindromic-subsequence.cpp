class Solution {
public:
    int f(int i, int j, string &s, string &r, vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == r[j]){
            return dp[i][j] = 1 + f(i-1,j-1,s,r,dp);
        }
        else{
            return dp[i][j] = max(f(i-1,j,s,r,dp),f(i,j-1,s,r,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string r = "";
        for(int i=n-1; i>=0; i--){
            r += s[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(n-1,n-1,s,r,dp);
    }
};