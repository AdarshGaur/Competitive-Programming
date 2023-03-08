#Author: @AdarshGaur

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def __init__(self):
        self.ans = float('inf')
        self.last = float('-inf')

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        if root.left:
            self.minDiffInBST(root.left)
        self.ans = min(self.ans, root.val - self.last)
        self.last = root.val
        if root.right:
            self.minDiffInBST(root.right)
        return self.ans

