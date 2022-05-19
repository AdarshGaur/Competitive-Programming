// Author : @AdarshGaur

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 1;
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1)
            return -1;
        if(n == 1) return 1;
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            for(int k=0; k<8; k++){
                int x = i + dx[k], y = j + dy[k];
                if(x>=0 and x<n and y>=0 and y<n and grid[x][y] == 0){
                    if(x==n-1 and y==n-1) return grid[i][j]+1;
                    q.push({x,y});
                    grid[x][y] = grid[i][j] +1;
                }
            }
        }
        return -1;
    }
};
