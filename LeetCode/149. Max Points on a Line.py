#Author: @AdarshGaur

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        ans, n = 0, len(points)
        for i in range(n):
            cnt = {}
            for j in range(i+1, n):
                slope = 0
                if points[i][0] == points[j][0]:
                    slope = float('inf')
                else:
                    slope = (points[j][1] - points[i][1])/(points[j][0] - points[i][0])
                s = cnt.get(slope, 0)
                cnt[slope] = s +1
            
            mx = 0
            for v in cnt.values():
                mx = max(mx, v)
            ans = max(ans, mx+1)
        return ans

