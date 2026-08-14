class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1; 

        for(auto neighbour: adj[node]){
            if(!vis[neighbour]){
                if(dfs(neighbour,adj,vis,pathVis)==true){
                    return true;
                }
            }
            else if(pathVis[neighbour]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for(auto p : prerequisites){
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course);
        }

        vector<int> vis(n,0);
        vector<int> pathVis(n,0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)==true){
                    return false;
                }
            }   
        }

        return true; 
    }
};

