// Author : @AdarshGaur

class Solution {
public:
    int n, ans, timer=1;
    pair<int,int> d[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<int>>& g, int i, int j, int& timer, int& cnt){
        if(i<0 or j<0 or i>=n or j>=n or g[i][j]!=1) return;
        g[i][j] = timer;
        cnt++;
        for(auto &[x, y]: d){
            dfs(g, i+x, j+y, timer, cnt);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;
        n = grid.size(), ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    timer++;
                    int cnt = 0;
                    dfs(grid, i, j, timer, cnt);
                    mp[timer] = cnt;
                    ans = max(ans, cnt);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    int cnt = 0;
                    set<int> s;
                    for(auto &[dx, dy]: d){
                        int x = i+dx, y=j+dy;
                        if(x>=0 and y>=0 and x<n and y<n and grid[x][y]!=0 and s.find(grid[x][y])==s.end()){
                            s.insert(grid[x][y]);
                            cnt += mp[grid[x][y]];
                        }
                    }
                    ans = max(ans, cnt+1);
                }
            }
        }
        return ans;
    }
};
