#Author: @AdarshGaur

class Solution:
    def numSquares(self, n: int) -> int:
        dp = [0] * (n+1)
        for i in range(1, n+1):
            j, temp = 1, i
            while j*j <= i:
                temp = min(temp, dp[i - j*j] +1)
                j += 1
            dp[i] = temp
        return dp[n]
