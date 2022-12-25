#Author: @AdarshGaur

class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        ans, last = 0, float('-inf') 
        for x, y in sorted(pairs, key = operator.itemgetter(1)):
            if last < x:
                last = y
                ans += 1
        return ans
