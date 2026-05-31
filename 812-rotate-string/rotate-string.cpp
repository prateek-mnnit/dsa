class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n != goal.size()){
            return false;
        }
        string ans = s;
        for(int i=0; i<n; i++){
            ans = ans.substr(1,n-1) + ans[0]; 
            if(ans == goal){
                return true;
            }
        }
        return false;

    }
};