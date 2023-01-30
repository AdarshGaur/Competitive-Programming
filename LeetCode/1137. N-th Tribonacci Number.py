#Author: @AdarshGaur

class Solution:
    def tribonacci(self, n: int) -> int:
        dp = [0 for _ in range(n+7)]
        dp[1] = 1
        for i in range(n):
            dp[i+1] += dp[i]
            dp[i+2] += dp[i]
            dp[i+3] += dp[i]
        return dp[n]
