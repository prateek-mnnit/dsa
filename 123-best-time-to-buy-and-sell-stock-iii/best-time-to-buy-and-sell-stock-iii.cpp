class Solution {
public:
    int f(int idx,int buy,int n,int count,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(idx == n || count == 2)
            return 0;
        if(dp[idx][buy][count] != -1)
            return dp[idx][buy][count];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + f(idx+1,0,n,count,prices,dp),
                                            f(idx+1,1,n,count,prices,dp));
        }
        else{
            profit = max(prices[idx] + f(idx+1,1,n,count+1,prices,dp),
                                            f(idx+1,0,n,count,prices,dp));
        }

        return dp[idx][buy][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1))
        );
        return f(0,1,n,0,prices,dp);

    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int minn = prices[0];
//         int maxprof = 0;
//         int first = 0;
//         int second = 0;
//         for (int i = 1; i < n; i++) {
//             if (prices[i] < prices[i - 1]) {
//                 if (maxprof >= first) {
//                     second = first;
//                     first = maxprof;
//                 } else if (maxprof > second) {
//                     second = maxprof;
//                 }
//                 minn = prices[i];
//                 maxprof = 0;
//             } else {
//                 int cost = prices[i] - minn;
//                 maxprof = max(maxprof, cost);
//                 minn = min(minn, prices[i]);
//             }
//         }
//         if (maxprof >= first) {
//             second = first;
//             first = maxprof;
//         }else if (maxprof > second) {
//                     second = maxprof;
//         }

//         return first + second;
//     }
// };