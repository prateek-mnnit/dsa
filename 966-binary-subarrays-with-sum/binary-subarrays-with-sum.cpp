class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        int preSum = 0;
        int remove = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;

        for(int i=0; i<n; i++){
            preSum += nums[i];
            remove = preSum - goal;
            count += mp[remove];
            mp[preSum]++;
        }
        
        return count;
    }
};