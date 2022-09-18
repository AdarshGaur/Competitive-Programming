# Author : @AdarshGaur

class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        ans = 0
        for i in range(1, n-1):
            less, more = 0, 0
            for j in range(0, i):
                less += (rating[j] < rating[i])
            for j in range(i+1, n):
                more += (rating[j] > rating[i])
            ans += (more * less) + ((i - less) * (n - i - 1 - more))        
        return ans
