// Author : @AdarshGaur

class Solution {
public:
    int n, m;
    int d[5] = {0, 1, 0, -1, 0};
    
    void dfs(vector<vector<bool>>& c, vector<vector<int>>& h, int x, int y){
        c[x][y] = true;
        for(int i=0; i<4; i++){
            int nx = x + d[i], ny = y + d[i+1];
            if(nx < 0 or ny < 0 or nx == n or ny == m or c[nx][ny] or h[nx][ny] < h[x][y]) continue;
            dfs(c, h, nx, ny);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<bool>> c1(n, vector<bool>(m, false));
        auto c2 = c1;
        for(int i=0; i<n; i++){
            if(c1[i][0] == 0)
                dfs(c1, heights, i, 0);
            if(c2[i][m-1] == 0)
                dfs(c2, heights, i, m-1);
        }
        for(int j=0; j<m; j++){
            if(c1[0][j] == 0)
                dfs(c1, heights, 0, j);
            if(c2[n-1][j] == 0)
                dfs(c2, heights, n-1, j);
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(c1[i][j] and c2[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
