class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int sz = flights.size();
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});        
        }   
        //{stops,dist,node}
        queue<tuple<int,int,int>> q;
        vector<int> dist(n,1e9);
        q.push({0,0,src});
        dist[src] = 0;

        while(!q.empty()){
            auto [stops,cost,node] = q.front();
            q.pop();

            if(stops>k)
                continue;

            for(auto it:adj[node]){
                int neighbour = it.first;
                int nextcost = it.second;

                if(dist[neighbour] > cost + nextcost && stops<=k){
                    dist[neighbour] = cost + nextcost;
                    q.push({stops+1,dist[neighbour],neighbour});
                }
            }
        }
        if(dist[dst] != 1e9){
            return dist[dst];
        }
        return -1;
    }
};