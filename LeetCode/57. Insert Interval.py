# Author : @AdarshGaur

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        start , end = newInterval[0] , newInterval[1]
        left , right = [] , []
        for v in intervals:
            if v[1] < start:
                left += v,
            elif end < v[0]:
                right += v,
            else:
                start = min(start, v[0])
                end = max(end, v[1])
        return left + [[start, end]] + right
