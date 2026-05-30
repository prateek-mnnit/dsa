class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int n = s.size();
        string ans = "";

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                if(count>0){
                    ans = ans + s[i];
                }
                count++;
            }
            else if(s[i] == ')'){
                if(count>1){
                    ans = ans + s[i];
                }
                count--;
            }
        }
        return ans;
    }
};