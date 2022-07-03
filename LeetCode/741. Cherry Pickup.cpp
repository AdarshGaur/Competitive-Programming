// Author : @AdarshGaur

class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    
    int pickUp(int x1, int y1, int x2, vector<vector<int>>& grid){
        // x1 + y1 = x2 + y2;
        int y2 = x1 + y1 - x2;
        
        if(x1 == n or x2 == n or y1 == n or y2 == n) return INT_MIN;
        if(grid[x1][y1] == -1 or grid[x2][y2] == -1) return INT_MIN;
        if(x1 == n-1 and y1 == n-1) return grid[x1][y1];
        if(dp[x1][y1][x2] != INT_MIN) return dp[x1][y1][x2];
        
        dp[x1][y1][x2] = grid[x1][y1] + (x1 == x2 and y1 == y2 ? 0 : grid[x2][y2]);
        dp[x1][y1][x2] += max({pickUp(x1+1, y1, x2, grid), pickUp(x1+1, y1, x2+1, grid), pickUp(x1, y1+1, x2, grid), pickUp(x1, y1+1, x2+1, grid)});
        return dp[x1][y1][x2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(0, pickUp(0,0,0, grid));
    }
};
