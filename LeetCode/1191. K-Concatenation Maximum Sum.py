#Author: @AdarshGaur

class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        tsum, best, n = 0, 0, len(arr)
        if k > 1 : n *= 2
        for i in range(n):
            tsum = max(0, tsum + arr[i % len(arr)])
            best = max(best, tsum)
        
        if k > 1: best = max(best, (k-2)*sum(arr) + best)
        best %= (10**9 +7)
        return best
