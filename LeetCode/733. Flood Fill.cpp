// Author : @AdarshGaur

class Solution {
public:
    pair<int,int> d[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        q.push({sr, sc});
        vis[sr][sc] = true;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(auto [i,j]: d){
                i += x, j += y;
                if(i>=0 and i<n and j>=0 and j<m and !vis[i][j] and image[i][j] == image[sr][sc]){
                    q.push({i,j});
                    vis[i][j] = true;
                    image[i][j] = color;
                }
            }
        }
        image[sr][sc] = color;
        return image;
    }
};
