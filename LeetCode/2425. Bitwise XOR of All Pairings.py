#Author: @AdarshGaur

class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        ans = 0
        ans ^= reduce(lambda a, b: a^b, nums2) if len(nums1) %2 != 0 else 0
        ans ^= reduce(lambda a, b: a^b, nums1) if len(nums2) %2 != 0 else 0
        return ans

