#Author: @AdarshGaur

class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        for v in cuboids:
            v.sort()
        cuboids.sort()
        ans, n = 0, len(cuboids)
        best = [0 for i in range(n)]
        for i in range(n):
            best[i] = cuboids[i][-1]
            for j in range(i):
                if cuboids[i][0] >= cuboids[j][0] and cuboids[i][1] >= cuboids[j][1] and cuboids[i][2] >= cuboids[j][2]:
                    best[i] = max(best[i], best[j] + cuboids[i][2])
            ans = max(ans, best[i])
        return ans
            
        
