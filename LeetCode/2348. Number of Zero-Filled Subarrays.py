#Author: @AdarshGaur

class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans, cnt = 0, 0
        for val in nums:
            if val == 0:
                cnt += 1
            else:
                ans += (cnt * (cnt + 1))//2
                cnt = 0
        ans += (cnt * (cnt+1))//2
        return ans

