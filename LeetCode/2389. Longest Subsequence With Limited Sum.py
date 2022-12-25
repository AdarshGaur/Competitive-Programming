#Author: @AdarshGaur

class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums = sorted(nums)
        for i in range(1, len(nums)):
            nums[i] += nums[i-1]
        ans = [0 for _ in range(len(queries))]
        for i, q in enumerate(queries):
            ans[i] = bisect.bisect(nums, q)
        return ans

