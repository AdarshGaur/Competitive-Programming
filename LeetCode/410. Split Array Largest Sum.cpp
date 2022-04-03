// Atuhor : Adarsh Gaur

class Solution {
public:
    int splitArray(vector<int>& a, int m) {
        int INF = 1e9 +7, n = a.size();
        vector<int> pref(n+1, 0);
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        for(int i=1; i<=n; i++){
            pref[i] += pref[i-1] + a[i-1];
            dp[1][i] = pref[i];
        }
        for(int i=2; i<=m; i++){
            for(int j=1; j<=n; j++){
                int mn = INF;
                for(int k = j-1; k >= i-1; k--){
                    if(dp[i-1][k] == -1)break;
                    int x = max(dp[i-1][k], pref[j] - pref[k]);
                    mn = min(mn, x);
                }
                if(mn == INF) mn = -1;
                dp[i][j] = mn;
            }
        }
        return dp[m][n];
    }
};
