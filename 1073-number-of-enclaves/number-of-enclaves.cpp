class Solution {
public:
    int n , m;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[r][c] = 1;

        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr<n && nr>=0 &&
                nc<m && nc>=0 &&
                !vis[nr][nc] &&
                grid[nr][nc] == 1){
                    dfs(nr,nc,grid,vis);
                }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i,0,grid,vis);
            }

            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(i,m-1,grid,vis);
            }
        }

        for(int j=0; j<m; j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                dfs(0,j,grid,vis);
            }

            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                dfs(n-1,j,grid,vis);
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;

    }
};