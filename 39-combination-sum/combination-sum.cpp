class Solution {
public:
    vector<vector<int>> vec;
    void f(int idx,int sum,int target,vector<int>& v,vector<int>& candidates){
        if(sum == target){
            vec.push_back(v);
            return ;

        }
        if (idx >= candidates.size() || sum > target) {
            return;
        }

        
            v.push_back(candidates[idx]);
            f(idx,sum+candidates[idx],target,v,candidates);
        
        
            v.pop_back();
            f(idx+1,sum,target,v,candidates);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        f(0,0,target,v,candidates);
        return vec;
    }
};