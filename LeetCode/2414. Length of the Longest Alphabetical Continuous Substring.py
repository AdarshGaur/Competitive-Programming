# Author : @AdarshGaur

class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        ans, cur = 1, 1
        for i in range(1, (len(s))):
            if ord(s[i]) - ord(s[i-1]) == 1:
                cur += 1
                ans = max(ans, cur)
            else:
                cur = 1
        return ans
