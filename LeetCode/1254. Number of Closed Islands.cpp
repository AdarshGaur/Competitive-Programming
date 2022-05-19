// Author : @AdarshGaur

class Solution {
public:
    int n, m;
    pair<int,int> neigh[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x<0 or y<0 or x>=n or y>=m or grid[x][y]!=0) return;
        grid[x][y] = 1;
        for(auto &[i, j]: neigh)
            dfs(grid, x+i, y+j);
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i=0; i<m; i++){
            if(grid[0][i] == 0) dfs(grid, 0, i);
            if(grid[n-1][i] == 0) dfs(grid, n-1, i);
        }
        for(int i=0; i<n; i++){
            if(grid[i][0] == 0) dfs(grid, i, 0);
            if(grid[i][m-1] == 0) dfs(grid, i, m-1);
        }
        int ans = 0;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(grid[i][j] == 0)
                    ans++, dfs(grid, i, j);
            }
        }
        return ans;
    }
};
