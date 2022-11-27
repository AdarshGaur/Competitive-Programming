#Author: @AdarshGaur

class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        n = len(startTime)
        arr = sorted(list(zip(startTime, endTime, profit)))
        startTime.sort()
        
        @lru_cache(None)
        def dp(i):
            if i == n : return 0
            best = dp(i+1)
            
            j = bisect_left(startTime, arr[i][1])
            best = max(best, dp(j) + arr[i][2])
            return best
        
        return dp(0)
