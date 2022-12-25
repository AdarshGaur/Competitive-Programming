#Author: @AdarshGaur

class Solution:
    # def checkRecord(self, n: int) -> int:
    #     dp = [[1,1,1], [1,1,1], [3,2,3],]
    #     mod = 10**9 +7
    #     for i in range(3, n+1):
    #         p = (dp[-1][0] + dp[-1][1] + dp[-1][2])%mod
    #         a = (dp[-1][1] + dp[-2][1] + dp[-3][1])%mod
    #         l = (dp[-1][0] + dp[-1][1] + dp[-2][0] + dp[-2][1]) %mod
    #         dp.append([p, a, l])
    #     return (dp[n][0] + dp[n][1] + dp[n][2])%mod


    def checkRecord(self, n: int) -> int:
        # types of list ending : "..L", "..LL", "...P"
        # ends with P, L, LL
        endsWithP, endsWithL, endsWithLL, mod = 1, 1, 0, 10**9 +7
        dp = [1, 2]
        for i in range(2, n+1):
            endsWithP, endsWithL, endsWithLL = endsWithP + endsWithL + endsWithLL, endsWithP, endsWithL
            dp.append((endsWithP + endsWithL + endsWithLL) % mod)
            endsWithP %= mod
            endsWithL %= mod
            endsWithLL %= mod
        endsWithA = 0
        for i in range(1, n+1):
            endsWithA += (dp[i-1] * dp[n-i]) % mod
        return (endsWithA + dp[n]) %mod

