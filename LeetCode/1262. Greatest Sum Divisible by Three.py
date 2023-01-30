#Author: @AdarshGaur

class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [0, 0, 0]
        for val in nums:
            for v in dp[:]:
                dp[(v + val) %3] = max(dp[(v+val)%3], v + val)
        return dp[0]

