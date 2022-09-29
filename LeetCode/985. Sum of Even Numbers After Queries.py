# Author : @AdarshGaur

class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        ssum = 0
        ans = []
        for i in nums:
            if i % 2 == 0:
                ssum += i
        for v, j in queries:
            if nums[j] % 2 == 0:
                ssum -= nums[j]
            nums[j] += v
            if nums[j] % 2 == 0:
                ssum += nums[j]
            ans.append(ssum)        
        return ans
