class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }   

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, 1e9);
        pq.push({0,k});
        dist[k] = 0;

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int neighbour = it.first;
                int edgeweight = it.second;

                if(dist[neighbour] > dis + edgeweight){
                    dist[neighbour] = dis + edgeweight;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        int time = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9) 
                return -1;
            else if(time<dist[i])
                time = dist[i];
        }

        return time;
    }
};