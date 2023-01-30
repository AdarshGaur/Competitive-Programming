#Author: @AdarshGaur

from collections import deque
class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        if node1 == node2: return node2
        n = len(edges)
        color = [-1] * n
        color[node1] = 0
        color[node2] = 1
        dq = deque([node1, node2])
        while len(dq) != 0:
            min_indx, size = n, len(dq)
            found = False
            for i in range(size):
                u = dq.popleft()
                v = edges[u]
                c = color[u]
                if v == -1 : continue
                if color[v] == c ^ 1:
                    found = True
                    min_indx = min(min_indx, v)
                elif color[v] == -1:
                    color[v] = c
                    dq.append(v)
            if found:
                return min_indx
        return -1
        

