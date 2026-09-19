class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = 0;
        int minn = prices[0];
        int n = prices.size();

        for(int i=1; i<n; i++){
            int profit = prices[i] - minn;
            maxprof = max(maxprof,profit);
            minn = min(minn,prices[i]);
        }
        return maxprof;
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int max_profit = 0;
//         int last = prices[n-1];
//         stack<int> s;

//         for(int i=0; i<n-1; i++){
//             s.push(prices[i]);
//         }
//         for(int i=0; i<n-1; i++){
//             max_profit = max(max_profit, last-s.top());
//             last = max(last, s.top());
//             s.pop();
//         }
//         return max_profit;

//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int bestBuy[100000];
//         bestBuy[0]=INT_MAX;
//         int maxProfit=0;
//         for(int i=1;i<prices.size();i++)
//         {
//             bestBuy[i]=min(bestBuy[i-1],prices[i-1]);
//         }

//         for(int i=0;i<prices.size();i++)
//         {
//             int currentProfit=prices[i]-bestBuy[i];
//             maxProfit=max(maxProfit,currentProfit);
//         }
//         return maxProfit;
//     }
// };