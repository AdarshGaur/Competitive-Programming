// Author : @AdarshGaur

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] and grid[i][j] == 1){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = true;
                    int cnt = 1;
                    while(!q.empty()){
                        auto [ni, nj] = q.front();
                        q.pop();
                        for(int k=0; k<4; k++){
                            int x = ni + dx[k], y = nj + dy[k];
                            if(x >=0 and x<n and y>=0 and y<m and grid[x][y]==1 and !vis[x][y]){
                                q.push({x,y});
                                vis[x][y] = true;
                                cnt++;
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};
