class Solution {
public:

    int calculate_atmost(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int l=0, r=0;
        if(k<0){
            return 0;
        }
        unordered_map<int,int> mp;

        while(r<n){
            mp[nums[r]]++;

            while(mp.size() > k){
                mp[nums[l]]--;

                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }

            count = count + (r-l+1);
            r++;
        }
        return count;

    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int ans = calculate_atmost(nums,k) - calculate_atmost(nums,k-1);

        return ans;

    }
};