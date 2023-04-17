// Author: @AdarshGaur

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int total = 0, n = grid.size(), m = grid[0].size();
        for(auto &v: grid){
            for(auto &i: v){
                total += (i == 1 ? 1 : 0);
            }
        }
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 or j == 0 or i == n-1 or j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        vis[i][j] = true;
                    }
                }
            }
        }
        int d[5] = {1, 0, -1, 0, 1};
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            total -= 1;
            for(int i_=0; i_<4; i_++){
                int x = i + d[i_], y = j + d[i_+1];
                if(x>=0 and x<n and y>=0 and y<m and grid[x][y] == 1 and !vis[x][y]){
                    q.push({x,y});
                    vis[x][y] = true;
                }
            }
        }
        return total;
    }
};

