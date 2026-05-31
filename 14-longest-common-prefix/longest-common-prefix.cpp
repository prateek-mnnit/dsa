class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        char s = strs[0][0];
        string ans = "";

        int j = 0;
        bool tr = true;
        int siz = strs[0].size();

        for (int i = 1; i < n; i++) {
            siz = min(siz, (int)strs[i].size());
        }
        while (j < siz) {
            for (int i = 1; i < n; i++) {
                if (s == strs[i][j]) {
                    tr = true;
                } else {
                    tr = false;
                    break;
                }
            }
            j++;
            if (tr == true) {
                ans = ans + s;
                s = strs[0][j];
            } else {
                break;
            }
        }
        return ans;
    }
};