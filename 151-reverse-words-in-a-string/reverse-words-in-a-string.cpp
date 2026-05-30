class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> v;
        string word = "";
        string result = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                v.push_back(word);
                word = "";
            } else {
                word = word + s[i];
            }
        }
        v.push_back(word);
        int m = v.size();
        for (int i = m - 1; i >= 0; i--) {
            if (v[i] != "") {
                if (result == "") {
                    result = result + v[i];
                } else {

                    result = result + " " + v[i];
                }
            }
        }

        return result;
    }
};