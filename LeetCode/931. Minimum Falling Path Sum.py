#Author: @AdarshGaur

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        cache = [[0 for i in range(n)] for j in range(n)]
        for i in range(n-1, -1, -1):
            for j in range(n):
                cache[i][j] = matrix[i][j]
                if i < n-1:
                    mx = cache[i+1][j]
                    if j > 0: mx = min(mx, cache[i+1][j-1])
                    if j < n-1: mx = min(mx, cache[i+1][j+1])
                    cache[i][j] += mx
        return min(cache[0][i] for i in range(n))

