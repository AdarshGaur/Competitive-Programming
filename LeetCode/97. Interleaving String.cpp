// Author : @AdarshGaur

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n+m != s3.size()) return false;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i=1, j=0; i<= n && j<s3.size(); i++, j++){
            if(s1[i-1] == s3[j])
                dp[i][0] = dp[i-1][0];
        }
        for(int i=1, j=0; i<= m && j<s3.size(); i++, j++){
            if(s2[i-1] == s3[j])
                dp[0][i] = dp[0][i-1];
        }
        for(int i=1; i<=n; i++){
            for(int j=1, k=i; j<=m && k<s3.size(); j++, k++){
                if(s3[k] == s1[i-1])
                    dp[i][j] = dp[i-1][j];
                if(s3[k] == s2[j-1])
                    dp[i][j] = dp[i][j] or dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};
