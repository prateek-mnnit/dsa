class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minn = prices[0];
        int maxprof = 0;
        int ans = 0;
        for(int i=1; i<n; i++){
            if(prices[i] < prices[i-1]){
                ans += maxprof;
                minn = prices[i];
                maxprof = 0;
            }
            else{
                int cost = prices[i] - minn;
                maxprof = max(maxprof,cost);
                minn = min(minn,prices[i]);
            }
        }
        ans += maxprof;
        return ans;
    }
};