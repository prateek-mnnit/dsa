class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        //{time,freq}
        vector<pair<long long,int>> dist(n,{1e18,0});
        //{time,node}
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        dist[0] = {0,1};

        const int MOD = 1e9+7;
        while(!pq.empty()){
            auto [time,node] = pq.top();
            pq.pop();

            for(auto it : adj[node]){
                long long edgeweight = it.second;
                int neighbour = it.first;

                if(dist[neighbour].first > time + edgeweight){
                    dist[neighbour].first = time + edgeweight;
                    dist[neighbour].second = dist[node].second;
                    pq.push({dist[neighbour].first,neighbour}); 
                }
                else if(dist[neighbour].first == time + edgeweight){
                    dist[neighbour].second = (dist[neighbour].second + dist[node].second) % MOD;
                }
            }
        }

        return dist[n-1].second%MOD;

    }
};