// Author : @AdarshGaur

class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};
    vector<vector<bool>> vis;
    
    void dfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int i, int j, int& n, int& m, bool& pos){
        vis[i][j] = true;
        if(g1[i][j] != g2[i][j]) pos = false;
        for(int k=0; k<4; k++){
            int x = i + d[k], y = j + d[k+1];
            if(x>=0 and x<n and y>=0 and y<m and g2[x][y] == 1 and !vis[x][y])
                dfs(g1, g2, x, y, n, m, pos);
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size(), cnt = 0;
        vis.resize(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 and !vis[i][j]){
                    bool pos = true;
                    dfs(grid1, grid2, i, j, n, m, pos);
                    if(pos) cnt++;
                }
            }
        }
        return cnt;
    }
};
