// Author : @AdarshGaur

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(auto &v: guards)
            grid[v[0]][v[1]] = 2;
        for(auto &v: walls)
            grid[v[0]][v[1]] = -2;
        for(auto &v: guards){
            int i = v[0], j = v[1]+1;
            // RIGHT
            while(j<n and grid[i][j] != 2 and grid[i][j] != -2)
                grid[i][j++] = 1;
            i = v[0], j = v[1]-1;
            // LEFT
            while(j>=0 and grid[i][j] != 2 and grid[i][j] != -2)
                grid[i][j--] = 1;
            i = v[0]-1, j = v[1];
            // UP
            while(i>=0 and grid[i][j] != 2 and grid[i][j] != -2)
                grid[i--][j] = 1;
            i = v[0]+1, j = v[1];
            // DOWN
            while(i<m and grid[i][j] != 2 and grid[i][j] != -2)
                grid[i++][j] = 1;
        }
        int unsafe = 0;
        for(auto i: grid){
            for(auto j: i){
                unsafe += j == 0 ? 1 : 0;
            }
        }
        return unsafe;
    }
};
