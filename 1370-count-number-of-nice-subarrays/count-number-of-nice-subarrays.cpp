class Solution {
public:
    int calculate(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0, r=0;
        int count = 0;
        int temp_odd = 0;
        if(k<0){
            return 0;
        }
        while(r<n){
            if(nums[r]%2 != 0){
                    temp_odd++;
            }

            while(temp_odd > k){
            
                if(nums[l]%2 != 0){
                    temp_odd--;
                }
                l++;
            }
            count = count + (r-l+1);
            r++;

        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = calculate(nums,k) - calculate(nums,k-1);
        return ans;    
    }
};