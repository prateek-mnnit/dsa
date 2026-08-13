class Solution {
public:
    int n,m;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};

    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[r][c] = 1;

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr<n && nr>=0 && 
                nc<m && nc>=0 &&
                !vis[nr][nc] && 
                grid[nr][nc] == '1'){
                    dfs(nr,nc,grid,vis);
                }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));  
        int count = 0;
        for(int i=0; i<n; i++){
              for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    dfs(i,j,grid,vis);
                }
              }
        } 
        return count;
    }
};