#Author: @AdarshGaur

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        leafsq1, leafsq2 = [], []
        
        def dfs(root, sq):
            if root.left:
                dfs(root.left, sq)
            if root.right:
                dfs(root.right, sq)
            if root.left == None and root.right == None:
                sq.append(root.val)
            return
        
        dfs(root1, leafsq1)
        dfs(root2, leafsq2)

        return leafsq1 == leafsq2
