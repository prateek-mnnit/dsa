class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int vis[m][n];
        int fresh = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1)
                fresh ++;
            }
        }

        int time = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            time = max(t,time);
            q.pop();

            for(int i=0; i<4; i++){

                int neb_r = r + drow[i];
                int neb_c = c + dcol[i];

                if(neb_r >= 0 && neb_r < m &&
                    neb_c >= 0 && neb_c < n &&
                    vis[neb_r][neb_c] != 2 &&
                    grid[neb_r][neb_c] == 1){
                        q.push({{neb_r,neb_c},t+1});
                        vis[neb_r][neb_c] = 2;
                        fresh--;
                    }
            }

        
        }
        if(fresh != 0){
                return -1;
            }

            return time;
    }
};