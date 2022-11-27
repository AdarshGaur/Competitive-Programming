#Author: @AdarshGaur

class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        cache = [[0 for j in range(m)] for i in range(n)]
        for i in range(n):
            for j in range(m):
                cache[i][j] = nums1[i] * nums2[j]
                if i > 0 and j > 0:  cache[i][j] += max(cache[i-1][j-1], 0)
                if i > 0: cache[i][j] = max(cache[i][j], cache[i-1][j])
                if j > 0: cache[i][j] = max(cache[i][j], cache[i][j-1])
        return cache[n-1][m-1]
