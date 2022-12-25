#Author: @AdarshGaur

class Solution:
    def numDecodings(self, s: str) -> int:
        n, mod = len(s), 10**9 +7
        dp = [0 for _ in range(n+1)]
        dp[0] = 1
        for i in range(n):
            if s[i] == '*':
                dp[i+1] += dp[i] * 9
                if i > 0:
                    if s[i-1] == '1' or s[i-1] == '*':
                        dp[i+1] += dp[i-1] * 9
                    if s[i-1] == '2' or s[i-1] == '*':
                        dp[i+1] += dp[i-1] * 6
            else:
                if s[i] != '0':
                    dp[i+1] += dp[i]
                if i > 0:
                    if s[i-1] == '1' or s[i-1] == '*':
                        dp[i+1] += dp[i-1]
                    if (s[i-1] == '2' or s[i-1] == '*') and s[i] < '7' :
                        dp[i+1] += dp[i-1]
            dp[i+1] %= mod
        return dp[n]

