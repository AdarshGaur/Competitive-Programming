#Author: @AdarshGaur

class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        queue = collections.deque()
        queue.append([entrance[0], entrance[1]])
        maze[entrance[0]][entrance[1]] = '+'
        n, m, ans = len(maze), len(maze[0]), 0
        d = [1, 0, -1, 0, 1]
        while len(queue) > 0:
            sz = len(queue)
            for i in range(0, sz):
                pos = queue.popleft()
                for j in range(0, 4):
                    x = pos[0] + d[j]
                    y = pos[1] + d[j+1]
                    if x < 0 or y < 0 or x == n or y == m or maze[x][y] != '.': continue
                    if x == 0 or y == 0 or x == n-1 or y == m-1:
                        return ans+1
                    maze[x][y] = '+'
                    queue.append([x,y])
            ans += 1
        return -1
                    
            
