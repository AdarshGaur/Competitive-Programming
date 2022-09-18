#Author : @AdarshGaur

class Solution:
    def minimumMoney(self, t: List[List[int]]) -> int:
        ans , best  = 0, 0
        for i in range(len(t)):
            if t[i][1] < t[i][0]:
                best = max(best, t[i][1])
                ans += (t[i][0] - t[i][1])
            else:
                best = max(best, t[i][0])
        return ans + best
