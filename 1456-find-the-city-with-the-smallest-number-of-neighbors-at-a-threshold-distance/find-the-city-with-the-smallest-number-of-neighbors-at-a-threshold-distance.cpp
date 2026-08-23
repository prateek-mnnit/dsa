class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int cityName = 0;
        int citycount = INT_MAX;
        for(int i=0; i<n; i++){
            vector<vector<pair<int,int>>> adj(n);
            for(auto it : edges){
                adj[it[0]].push_back({it[1], it[2]});
                adj[it[1]].push_back({it[0], it[2]});
            }  

            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0,i});

            vector<int> dist(n,1e9);
            dist[i] = 0;

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
            int temp = 0;
            for(int j=0; j<n; j++){
                if(dist[j]<=distanceThreshold){
                    temp++;
                }
            }
            if(citycount>temp){
                citycount = temp;
                cityName = i;
            }
            if(citycount == temp){
                cityName = max(i,cityName);
            }

        }
        return cityName;
    }
};