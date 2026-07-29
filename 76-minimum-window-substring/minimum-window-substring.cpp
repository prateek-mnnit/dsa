class Solution {
public:
    string minWindow(string s, string t) {

        int m = s.size();
        int n = t.size();

        if (n > m)
            return "";

        vector<int> mp(256, 0);

        // Store frequency of characters in t
        for (int i = 0; i < n; i++) {
            mp[t[i]]++;
        }

        int l = 0, r = 0;
        int count = 0;
        int min_len = INT_MAX;
        int startIdx = -1;

        while (r < m) {

            // Include current character
            if (mp[s[r]] > 0)
                count++;

            mp[s[r]]--;

            // Shrink while window is valid
            while (count == n) {

                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    startIdx = l;
                }

                // Remove left character
                mp[s[l]]++;

                if (mp[s[l]] > 0)
                    count--;

                l++;
            }

            r++;
        }

        if (startIdx == -1)
            return "";

        return s.substr(startIdx, min_len);
    }
};