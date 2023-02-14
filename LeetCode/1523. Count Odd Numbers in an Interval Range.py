class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if low == high:
            return low & 1
        ans = 0
        if low & 1:
            low += 1
            ans += 1
        if high & 1:
            high -= 1
            ans += 1
        return ans + max(0, (high - low)//2)

