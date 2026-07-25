class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n==0 || n==1){
            return n;
        }
        int l=0, r=0;
        int max_len = 0;
        int max_freq = 0;

        vector<int> freq(26,0);
        
        while(r<n){
            freq[s[r]-'A']++;

            max_freq = max(freq[s[r]-'A'], max_freq);

            if((r-l+1) - max_freq > k){
                freq[s[l]-'A']--;
                l++;
            }

            max_len = max(max_len, r - l + 1);
            r++;
        }

        return max_len;

    }
};