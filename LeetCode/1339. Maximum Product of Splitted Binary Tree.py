#Author : @AdarshGaur

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        sums = []

        def dfs(root):
            if root == None: return 0
            s = root.val + dfs(root.left) + dfs(root.right)
            sums.append(s)
            return s
        
        total = dfs(root)
        return max((total - v) * v for v in sums) % (10**9 +7)

