class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0, r = 0;
        int maxi = 0;
        int temp = k;

        while(r<n){
            if(nums[r] == 1){
                maxi = max(maxi,r-l+1);
                r++;
            }
            else if(nums[r] == 0){
                if(temp>0){
                    maxi = max(maxi,r-l+1);
                    temp--;
                    r++;
                }
                else{
                    while(nums[l]!=0){
                        l++;
                    }
                    l++;
                    temp++;
                }
            }
        } 

        return maxi;    
    }
};