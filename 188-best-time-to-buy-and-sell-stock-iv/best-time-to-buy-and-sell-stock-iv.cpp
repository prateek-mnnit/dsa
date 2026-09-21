class Solution {
public:
    int f(int idx,int buy,int n,int count,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(idx == n || count == 0)
            return 0;
        if(dp[idx][buy][count] != -1)
            return dp[idx][buy][count];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + f(idx+1,0,n,count,prices,dp),
                                            f(idx+1,1,n,count,prices,dp));
        }
        else{
            profit = max(prices[idx] + f(idx+1,1,n,count-1,prices,dp),
                                            f(idx+1,0,n,count,prices,dp));
        }

        return dp[idx][buy][count] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k+1, -1))
        );
        return f(0,1,n,k,prices,dp);

    }
};


        
