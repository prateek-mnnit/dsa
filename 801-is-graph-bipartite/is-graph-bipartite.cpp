class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int clr){
        color[node] = clr;

        for(auto neighbour: graph[node]){
            if(color[neighbour] == -1){
                if(clr==0){
                    if(dfs(neighbour,graph,color,1)==false)
                        return false;
                }
                else{
                    if(dfs(neighbour,graph,color,0)==false)
                        return false;
                }
            }
            else{
                if(color[neighbour] == clr)
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n,-1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(dfs(i,graph,color,0) == false){
                    return false;
                }
            }
        }

        return true;
    }
};