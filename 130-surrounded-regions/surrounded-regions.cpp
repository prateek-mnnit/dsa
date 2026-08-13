class Solution {
public:
    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,1,0,-1};
    int row,col;

    void dfs(int r, int c, vector<vector<char>>&board, vector<vector<int>> &vis){
        vis[r][c] = 1;
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i]; 
            if(nr<row && nr>=0 &&
                nc<col && nc>=0 &&
                board[nr][nc] == 'O' &&
                !vis[nr][nc]){
                    dfs(nr,nc,board,vis);
            }
            
        }
    }
    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();

        vector<vector<int>> vis(row, vector<int>(col,0));

        for(int i=0; i<row; i++){
            if(board[i][0] == 'O'){
                if(!vis[i][0]){
                    dfs(i,0,board,vis);
                }
            }
        }
        for(int j=0; j<col; j++){
            if(board[0][j] == 'O'){
                if(!vis[0][j]){
                    dfs(0,j,board,vis);
                }
            }
        }
        for(int i=0; i<row; i++){
            if(board[i][col-1] == 'O'){
                if(!vis[i][col-1]){
                    dfs(i,col-1,board,vis);
                }
            }
        }
        for(int j=0; j<col; j++){
            if(board[row-1][j] == 'O'){
                if(!vis[row-1][j]){
                    dfs(row-1,j,board,vis);
                }
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};