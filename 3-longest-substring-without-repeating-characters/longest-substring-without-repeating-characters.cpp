class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0 || n==1){
            return n;
        }

        int l = 0;
        int r = 0;
        int max_len = 0;
        
        vector<int> v(256,-1);

        while(r<n){
            if(v[s[r]] != -1){
                if(v[s[r]] >= l){
                    l = v[s[r]] + 1;
                }
            }
            max_len = max(max_len, r-l+1);
            v[s[r]] = r;
            r++;
        }
        
        return max_len;
    }
};