// Author: @AdarshGaur

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1e9);
        for(int i=n-1; i>=0; i--){
            int take = 0;
            for(int j=0; j<3 and i+j<n; j++){
                take += stoneValue[i+j];
                int next = (i+j+1 < n ? dp[i+j+1] : 0);
                dp[i] = max(dp[i], take - next);
            }
        }
        if(dp[0] < 0) return "Bob";
        if(dp[0] > 0) return "Alice";
        return "Tie";
    }
};
