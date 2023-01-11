#Author: @AdarshGaur

class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        tree = defaultdict(list)
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)

        def dfs(root, par):
            ans = 0
            for v in tree[root]:
                if v == par: continue
                ans += dfs(v, root)
            if ans or hasApple[root]:
                ans += 2
            return ans
        
        return max(dfs(0, -1)-2, 0)

