class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l=0, r=n-1;
        int lSum = 0, rSum = 0;
        int maxSum = 0;
        while(l<k){
            lSum += cardPoints[l];
            l++;
        }
        maxSum = lSum;

        for(int i=k-1; i>=0; i--){
            lSum = lSum - cardPoints[i];
            rSum += cardPoints[r];
            maxSum = max(maxSum, lSum + rSum);
            r--;
        }

        return maxSum;
    }
};