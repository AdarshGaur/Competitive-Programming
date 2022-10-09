// Author : @AdarshGaur

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=2; i<n; i++){
            for(int j=2; j<m; j++){
                int cand = grid[i][j] + grid[i][j-1] + grid[i][j-2];
                cand += grid[i-1][j-1];
                cand += grid[i-2][j] + grid[i-2][j-1] + grid[i-2][j-2];
                ans = max(ans, cand);
            }
        }
        return ans;
    }
};
