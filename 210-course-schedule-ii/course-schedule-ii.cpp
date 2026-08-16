class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis,vector<int>& ans){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis,ans)){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node] = 0;
        ans.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it: prerequisites){
            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
        }

        vector<int> vis(numCourses);
        vector<int> pathVis(numCourses);
        vector<int> ans;
        vector<int> empty;

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis,ans) == true){
                    return empty;
                }
            }
        }

        int l=0, r=ans.size()-1;
        int temp;
        while(l<r){
            temp = ans[l];
            ans[l] = ans[r];
            ans[r] = temp;

            l++;
            r--;
        }
        return ans;
    }
};