// Author : @AdarshGaur

class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[2][1001] = {1};
        int mod = 1e9 +7;
        for (int N = 1; N <= n; ++N){
            for (int K = 0; K <= k; ++K) {
                dp[N % 2][K] = (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % mod;
                if (K >= N)
                    dp[N % 2][K] = (mod + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % mod;
            }
        }
        return dp[n % 2][k];
    }
};
