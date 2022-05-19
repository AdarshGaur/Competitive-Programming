// Author : @AdarshGaur

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j] = matrix[i-1][j-1];
                dp[i][j] += dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            }
        }
        int mx = INT_MIN;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                // ending cell marix[i][j]
                for(int ni=1; ni<=i; ni++){
                    for(int nj=1; nj<=j; nj++){
                        //starting cell matrix[ni][nj]
                        int sum = dp[i][j] - dp[i][nj-1] - dp[ni-1][j] + dp[ni-1][nj-1];
                        if(sum <= k and sum > mx)
                            mx = sum;
                    }
                }
            }
        }
        return mx;
    }
};
