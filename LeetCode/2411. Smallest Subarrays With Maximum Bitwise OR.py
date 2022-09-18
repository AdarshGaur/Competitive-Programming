# Author : @AdarshGaur

class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        ans = [1 for i in range(len(nums))]
        n = len(nums)
        for j in range(0, 30):
            last = n
            for i in range(n-1, -1, -1):
                if nums[i] & (1 << j):
                    last = i
                    continue
                if last != n:
                    ans[i] = max(ans[i], last - i +1)
        return ans
