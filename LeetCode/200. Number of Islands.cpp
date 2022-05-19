// Author : @AdarshGaur

class Solution {
public:
    pair<int,int> d[4]= {{-1,0}, {1,0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int x, int y, int& n, int& m){
        if(x<0 or x>=n or y<0 or y>=m or grid[x][y] == '0') return;
        grid[x][y] = '0';
        for(auto &[dx, dy]: d){
            dfs(grid, x+dx, y+dy, n, m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, n, m);
                    cnt++;
                }
        return cnt;
    }
};
