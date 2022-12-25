#Author: @AdarshGaur

class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [1, 1]
        for i in range(2, n+1):
            mx = 1
            for j in range(2, i):
                mx = max(mx, dp[j] * (i-j))
            
            if i != n: mx = max(mx, i)
            dp.append(mx)
        return dp[-1]

