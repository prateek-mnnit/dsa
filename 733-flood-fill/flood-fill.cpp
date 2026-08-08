class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int original;
    int n,m;

    void dfs(int sr,int sc, int color,vector<vector<int>> &image){
        image[sr][sc] = color;
        
        
        for(int i=0; i<4; i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];

            for(int j=0; j<4; j++){
                if(nr>=0 && nr<n &&
                   nc>=0 && nc<m &&
                   image[nr][nc] == original){

                    dfs(nr,nc,color,image);
                }
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();

        original = image[sr][sc];

        if(original == color){
            return image;
        }

        dfs(sr,sc,color,image);

        return image;
        


    }
};