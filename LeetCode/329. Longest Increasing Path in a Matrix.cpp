// Author : @AdarshGaur

class Solution {
public:
    vector<vector<int>> dp;
    int ans = 0, n, m;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    void dfs(vector<vector<int>>& matrix, int x, int y){
        int v = 0;
        for(int k=0; k<4; k++){
            int i = x+dx[k], j = y+dy[k];
            if(i>=0 and i<n and j>=0 and j<m and matrix[i][j] > matrix[x][y]){
                if(dp[i][j] == 0)
                    dfs(matrix, i, j);
                v = max(v, dp[i][j]);
            }
        }
        dp[x][y] = v+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, 0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dp[i][j]==0)
                    dfs(matrix, i, j);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
