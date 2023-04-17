# Author: @AdasrhGaur

class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        ans, pref = nums[0], nums[0]
        for i in range(1, len(nums)):
            pref += nums[i]
            ans = max(ans, math.ceil(pref/(i+1)))
        return ans

