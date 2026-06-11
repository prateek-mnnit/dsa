class Solution {
public:
    vector<vector<int>> vec;
    

    void f(int idx, vector<int>& v, vector<int> & nums){
        if(idx == nums.size()){
            vec.push_back(v);
            return;
        }
        v.push_back(nums[idx]);
        f(idx+1, v, nums);
        v.pop_back();

        int next = idx+1;
        while(next<nums.size() && nums[idx] == nums[next]){
            next++;
        }

        f(next, v, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        // vec.push_back({});
        f(0,v,nums);
        return vec;
    }
};