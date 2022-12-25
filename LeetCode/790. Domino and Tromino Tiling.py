#Author: @AdarshGaur

class Solution:
    def numTilings(self, n: int) -> int:
        dp = [0 for _ in range(n+3)]
        dp[0], dp[1], dp[2] = 1, 2, 5
        for i in range(3, n):
            dp[i] += 2*dp[i-1] + dp[i-3]
            dp[i] %= (10**9 +7)
        return dp[n-1]

