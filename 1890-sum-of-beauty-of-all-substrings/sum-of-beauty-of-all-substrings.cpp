class Solution {
public:
    int count_min(vector<int> freq){
        int minn = INT_MAX;
        for(int i=0; i<26; i++){
            if(freq[i]!=0){
                minn = min(minn, freq[i]);
            }
            
        }
        return minn;
    }
    int beautySum(string s) {
        int n = s.size();
        int maxi = 0;
        int minn = INT_MAX;
        int sum = 0;

        for(int i=0; i<n; i++){
            vector<int> freq(26,0);
            for(int j=i; j<n; j++){
                freq[s[j]-'a']++;
                maxi = *max_element(freq.begin(), freq.end());
                minn = count_min(freq);
                int beauty = maxi - minn;
                sum = sum + beauty;
            }
        }  
        return sum; 
    }
};