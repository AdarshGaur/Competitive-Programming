#Author: @AdarshGaur

class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0: return 1
        ans, cur = 10, 9
        for i in range(1, n):
            cur *= (10 - i)
            ans += cur
        return ans
