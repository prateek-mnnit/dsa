class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        vector<pair<char, int>> v;
        for (auto it : mp) {
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        string ans ="";
        int count = 0;
        int idx = 0;
        while(count<n){
            if(v[idx].second != 0){
                ans.push_back(v[idx].first);
                v[idx].second--;
                count++;
            }
            else{
                idx++;
            }
            
        }
        return ans;
    }
};