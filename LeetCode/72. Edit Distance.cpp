// Author: @AdarshGaur

class Solution {
public:
    int minDistance(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> dp(m+1);
        iota(dp.begin(), dp.end(), 0);
        for(int i=1; i<=n; i++){
            int x = dp[0];
            dp[0] = i;
            for(int j=1; j<=m; j++){
                int diagonal = x;
                x = dp[j];
                if(s[i-1] == p[j-1])
                    dp[j] = diagonal;
                else
                    dp[j] = min({diagonal, dp[j-1], dp[j]}) + 1;
            }
        }
        return dp[m];
    }
};
