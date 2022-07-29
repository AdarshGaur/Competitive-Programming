// Author : @AdarshGaur

class Solution {
public:
    int d[5] = {0, 1, 0, -1, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int time = 0, fresh = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto [u, v] = q.front();
                q.pop();
                for(int j=0; j<4; j++){
                    int x = d[j] +u, y = d[j+1] +v;
                    if(x < 0 or y < 0 or x == n or y == m or grid[x][y] != 1) continue;
                    grid[x][y] = 2;
                    fresh--;
                    q.push({x,y});
                }
            }
            if(!q.empty()) time++;
        }
        return (fresh == 0 ? time : -1);
    }
};
