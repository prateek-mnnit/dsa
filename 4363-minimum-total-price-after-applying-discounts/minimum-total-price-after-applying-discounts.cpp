class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();

        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        double sum = 0;
        

        int i = n-1;
        int j = m-1;
        while(i>=0 && j>=0){
            double dis = (prices[i]*(100.0-discounts[j]))/100.0;
            sum = sum + dis;
            i--;
            j--;
            
        }

        while(i>=0){
            sum = sum+ prices[i];
            i--;
        }
        return sum;
        
    }
};