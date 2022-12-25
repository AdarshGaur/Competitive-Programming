#Author: @AdarshGaur

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        to_Delete = set(to_delete)
        ans = []
        def dfs(cur, par_exist):
            if cur == None:
                return None
            if cur.val in to_Delete:
                cur.left = dfs(cur.left, False)
                cur.right = dfs(cur.right, False)
                return None
            if par_exist == False:
                ans.append(cur)
            cur.left = dfs(cur.left, True)
            cur.right = dfs(cur.right, True)
            return cur
        dfs(root, False)
        return ans 
