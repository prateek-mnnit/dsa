class Solution {
public:
    vector<vector<string>> vec;
    bool isSafe(int row, int col, int n, vector<string>& v){
        int tempCol = col;
        int tempRow = row;

        while(row>=0 && col>=0){
            if(v[row][col] == 'Q') return false;
            row--;
            col--;
        }

        col = tempCol;
        row = tempRow;

        while(col>=0){
            if(v[row][col] == 'Q') return false;
            col--;
        }

        col = tempCol;
        row = tempRow;

        while(row<n && col>=0){
            if(v[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void f(int col, int n, vector<string>& v){
        if(col == n){
            vec.push_back(v);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(row,col,n,v)){
                v[row][col] = 'Q';
                f(col+1, n, v);
                v[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n);
        string str(n,'.');
        for(int i=0; i<n; i++){
            v[i] = str;
        }
        f(0,n,v);
        return vec;
    }
};