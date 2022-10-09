# Author : @AdarshGaur

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = [1] * len(nums)
        pref = suf = 1
        for i in range(len(nums)):
            ans[i] *= pref
            ans[-1-i] *= suf
            pref *= nums[i]
            suf *= nums[-1-i]
        
        return ans;
