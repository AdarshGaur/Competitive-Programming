// Author: @AdarshGaur

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        if(q.empty() or q.size() == n*n) return -1;
        int distance = 0;
        int d[5] = {1, 0, -1, 0, 1};
        while(!q.empty()){
            for(int i_ = q.size(); i_>0; i_--){
                auto [i, j] = q.front();
                q.pop();
                for(int k = 0; k<4; k++){
                    int x = i + d[k], y = j + d[k+1];
                    if(x < 0 or x == n or y == n or y < 0 or visited[x][y]) continue;
                    q.push({x,y});
                    visited[x][y] = true;
                }
            }
            if(!q.empty())
                distance += 1;
        }
        return distance;
    }
};

