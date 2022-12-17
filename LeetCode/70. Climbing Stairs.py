#Author : @AdarshGaur

class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0, 1, 2]
        for i in range(3, n+1):
            dp.append(dp[-1] + dp[-2])
        return dp[n]


