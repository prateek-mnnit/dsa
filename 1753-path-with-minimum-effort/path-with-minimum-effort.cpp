class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        int neweffort = 0;

        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            for(int i=0; i<4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];
                
                if(newr<n && newr>=0 &&
                    newc<m && newc>=0 )
                {
                    int edgeweight = abs(heights[newr][newc]-heights[row][col]);
                    neweffort = max(dis,edgeweight);
                    if(dist[newr][newc] > neweffort){
                        dist[newr][newc] = neweffort;
                        pq.push({dist[newr][newc],{newr,newc}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
          
    }
};