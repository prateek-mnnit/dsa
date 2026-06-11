class Solution {
public:
    vector<vector<int>> vec;

    void f(int idx, int sum,int count, int k, int n, vector<int>& v, vector<int>& nums){
        if(idx == 9){
            if(count == k && sum == n){
                vec.push_back(v);
            }
            return;
        }

        v.push_back(nums[idx]);
        f(idx+1, sum+nums[idx], count+1, k, n, v, nums);
        v.pop_back();
        f(idx+1, sum, count, k, n, v, nums);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> v;
        if(k>n){
            return vec;
        }
        f(0,0,0,k,n,v,nums);

        return vec;
    }
};