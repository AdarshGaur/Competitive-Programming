#Author: @AdarshGaur

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        mx = max(nums)
        ans , cnt = 0, 0
        for i in nums:
            if i == mx :
                cnt += 1
            else:
                cnt = 0
            ans = max(ans, cnt)
        return ans
