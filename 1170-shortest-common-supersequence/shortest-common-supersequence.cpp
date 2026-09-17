// class Solution {
// public:
//     string f(int i, int j, string &str1, string &str2,vector<vector<string>> &dp){
//         if(i < 0 || j<0){
//             if(i<0){
//                 return str2.substr(0,j+1);
                
//             }
//             else{
//                 return str1.substr(0,i+1);
                
//             }
//         }
//         if(dp[i][j] != "")
//             return dp[i][j];

//         if(str1[i] == str2[j]){
//             return dp[i][j] = f(i-1,j-1,str1,str2,dp) + str1[i]; 
//         }
//         else{
//             string one = f(i-1,j,str1,str2,dp) + str1[i];
//             string two = f(i,j-1,str1,str2,dp) + str2[j];
//             if(one.size() < two.size()){
//                 return dp[i][j] = one;
//             }
//             else{
//                 return dp[i][j] = two;
//             }
//         }
//     }
//     string shortestCommonSupersequence(string str1, string str2) {
//         int n = str1.size();
//         int m = str2.size();
//         vector<vector<string>> dp(n,vector<string>(m,""));
//         return f(n-1,m-1,str1,str2,dp);
        
//     }
// };

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        // LCS DP
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Construct SCS using the LCS table
        int i = n;
        int j = m;

        string ans = "";

        while(i > 0 && j > 0) {

            if(str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            }
            else {
                ans += str2[j - 1];
                j--;
            }
        }

        // Remaining characters
        while(i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while(j > 0) {
            ans += str2[j - 1];
            j--;
        }

        // We constructed it backwards
        reverse(ans.begin(), ans.end());

        return ans;
    }
};