# Author : @AdarshGaur

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        a = sorted(nums)
        for i in range(len(a)-3, -1, -1):
            if a[i] + a[i+1] > a[i+2]:
                return a[i] + a[i+1] + a[i+2]
        return 0
