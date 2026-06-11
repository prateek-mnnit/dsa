class Solution {
public:
    vector<string> genParen(int open, int close, string st, int n, vector<string>& v){
        if(open == n && close == n){
            v.push_back(st);
            return v;
        }
        if(open<n){
            genParen(open+1,close,st+'(',n,v);
        }
        if(close<open){
            genParen(open,close+1,st+')',n,v);
        }
        return v;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string st = "";
        int open = 0;
        int close = 0;

        return genParen(open,close,st,n,v);
    }
};