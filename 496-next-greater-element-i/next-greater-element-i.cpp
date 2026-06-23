class Solution {
public:
    void inserting(vector<int>& ans, int j, int n2, vector<int>& nums2){
        for(int i=j; i<n2; i++){
            if(nums2[j] < nums2[i]){
                ans.push_back(nums2[i]);
                return;
            }
        }
        ans.push_back(-1);
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(nums1[i] == nums2[j]){
                    inserting(ans,j,n2,nums2);
                    break;
                }
            }
        }  

        return ans;
    }
};