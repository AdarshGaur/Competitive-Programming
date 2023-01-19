#Author: @AdarshGaur

class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        tree = [[] for _ in range(n)]
        for a, b in edges:
            tree[a].append(b)
            tree[b].append(a)
        ans = [0] * n

        def dfs(root, par = -1):
            cnts = [0] * 26
            for child in tree[root]:
                if child == par: continue
                for label, val in enumerate(dfs(child, root)):
                    cnts[label] += val
            indx = ord(labels[root]) - ord('a')
            cnts[indx] += 1
            ans[root] = cnts[indx]
            return cnts
        
        dfs(0)
        return ans

