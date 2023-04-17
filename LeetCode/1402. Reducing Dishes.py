#Author: @AdarshGaur

class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        lst = sorted(satisfaction)
        suff, ans, cur_sum = 0, 0, 0
        for i in range(len(lst)-1, -1, -1):
            suff += lst[i]
            cur_sum += suff
            ans = max(ans, cur_sum)
        return ans

