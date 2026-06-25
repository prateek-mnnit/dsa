class Solution {
public:
    // void inserting(vector<int>& ans, int j, int n2, vector<int>& nums2){
    //     for(int i=j; i<n2; i++){
    //         if(nums2[j] < nums2[i]){
    //             ans.push_back(nums2[i]);
    //             return;
    //         }
    //     }
    //     ans.push_back(-1);
    // }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ngl(n2);

        stack<int> st;

        for (int i = n2-1; i>= 0; i--) {

            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty()) ngl[i] = -1;

            else ngl[i] = st.top();

            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(ngl[j]);
                    break;
                }
            }
        }

        return ans;
        
    }
};