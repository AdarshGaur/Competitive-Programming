// Author: @AdarshGaur

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        for(int i=1; i<=n; i++){
            for(int j=1; j*j <= i and !dp[i]; j++){
                dp[i] = !dp[i - j*j];
            }
        }
        return dp[n];
    }
};
