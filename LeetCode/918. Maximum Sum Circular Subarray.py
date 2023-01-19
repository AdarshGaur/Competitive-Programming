#Author: @AdarshGaur

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        # solve with min subarray and max subarray
        total, curMax, mx, curMin, mn = 0, 0, nums[0], 0, nums[0]
        for i in nums:
            total += i
            curMax = max(i, curMax + i)
            mx = max(mx, curMax)
            curMin = min(i, curMin + i)
            mn = min(mn, curMin)
        return mx if mx < 0 else max(mx, total - mn)

    # def maxSubarraySumCircular(self, nums: List[int]) -> int:
    #     s = sum(nums)
    #     p, maxp, ans, curSum = 0, 0, float('-inf'), 0
    #     for i in range(len(nums)):
    #         # for circular subarray
    #         ans = max(ans, s + maxp)
    #         s -= nums[i]
    #         p += nums[i]
    #         maxp = max(maxp, p)

    #         # for normal subarray
    #         curSum += nums[i]
    #         if curSum < nums[i]:
    #             curSum = nums[i]
    #         ans = max(ans, curSum)
    #     return ans

