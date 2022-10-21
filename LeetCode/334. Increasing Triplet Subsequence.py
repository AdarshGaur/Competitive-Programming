# Author: @AdarshGaur

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        i = float('inf')
        j = float('inf')
        for k in nums:
            if k < i:
                i = k
            elif i < k < j:
                j = k
            elif j < k:
                return True
        return False
