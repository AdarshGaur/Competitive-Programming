// Author: @AdarshGaur

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for(int i=0; i<n; i++){
            int mx = arr[i];
            for(int j=1; j<=k and i+j<=n; j++){
                mx = max(mx, arr[i+j-1]);
                dp[i+j] = max(dp[i+j], dp[i] + j * mx);
            }
        }
        return dp[n];
    }
};

