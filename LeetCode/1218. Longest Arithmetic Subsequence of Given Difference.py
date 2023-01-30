# Author: @AdarshGaur

class Solution:
    # def longestSubsequence(self, arr: List[int], difference: int) -> int:
    #     dct = {}
    #     for val in arr:
    #         v = 1
    #         if val - difference in dct.keys():
    #             v = dct[val - difference] +1
    #         if val in dct.keys():
    #             dct[val] = max(dct[val], v)
    #         else:
    #             dct[val] = v
    #     return max(dct.values())


    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        dct = collections.Counter()
        for val in arr:
            dct[val] = max(dct[val], dct[val - difference]+1)
        return max(dct.values())

