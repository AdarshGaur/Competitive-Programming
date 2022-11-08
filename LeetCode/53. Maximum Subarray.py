#Author : @AdarshGaur

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        lmax , gmax = nums[0], nums[0]
        for i in range(1, len(nums)):
            lmax += nums[i]
            if lmax <= nums[i]:
                lmax = nums[i]
            gmax = max(lmax, gmax)
        return gmax
