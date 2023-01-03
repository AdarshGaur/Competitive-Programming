#Author: @AdarshGaur

class Solution:
    def knightDialer(self, n: int) -> int:
        dp = [1 for _ in range(10)]
        k = [[4,6], [6,8], [7,9], [4,8], [3,9,0], [], [1,7,0], [2,6], [1,3], [2,4]]
        for i_ in range(1, n):
            nxt = [0] * 10
            for i in range(10):
                for j in range(len(k[i])):
                    nxt[i] += dp[k[i][j]]
                nxt[i] %= (10**9 +7)
            dp = nxt
        return sum(dp) % (10**9 +7)
        
