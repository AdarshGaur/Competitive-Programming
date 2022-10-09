# Author : @AdarshGaur

class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        total = mx = 0
        for i in range(len(colors)):
            if i > 0 and colors[i-1] != colors[i]:
                mx = 0
            total += min(mx, neededTime[i])
            mx = max(mx, neededTime[i])
        return total

