#Author: @AdarshGaur

class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        max1, max0, ans = arr[0], arr[0], arr[0]
        for a in arr[1:]:
            max1 = max(max1 + a, max0, a)
            max0 = max(max0 + a, a)
            ans = max(ans, max1)
        return ans

