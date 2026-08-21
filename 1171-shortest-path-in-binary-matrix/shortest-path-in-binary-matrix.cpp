class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        if(n==1)
            return 1;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        queue<tuple<int,int,int>> q;

        q.push({0, 0, 1});
        vis[0][0] = 1;

        int dr[8] = {-1,-1,0,1,1,1,0,-1};
        int dc[8] = {0,1,1,1,0,-1,-1,-1};
        int ans = INT_MAX;

        while(!q.empty()) {
            auto [row, col, dist] = q.front();
            q.pop();

            for(int i = 0; i < 8; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr<n && nr>=0 && 
                    nc<n && nc>=0 &&
                    grid[nr][nc] == 0 &&
                    !vis[nr][nc]){
                        if(nr == n-1 && nc == n-1){
                            return dist+1;
                        }
                        vis[nr][nc] = 1;
                        q.push({nr,nc,dist+1});
                }
                
            }
        }
        return -1;
    }
};