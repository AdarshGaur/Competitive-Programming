#Author: @AdarshGaur

class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        dp = [0 for _ in range(len(s)+1)]
        dp[0] = 1
        n = len(s)
        for i in range(n):
            if s[i] == '0': continue
            cur = 0
            for j in range(i, n):
                cur += ord(s[j]) - ord('0')
                if cur > k: break
                if cur == 0: continue
                cur *= 10
                dp[j+1] += dp[i]
                dp[j+1] %= (10**9 +7)
        return dp[-1]

