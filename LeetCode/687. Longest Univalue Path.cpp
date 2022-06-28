// Author : @AdarshGaur

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int& maxPath){
        if(!root) return 0;
        int l = dfs(root->left, maxPath);
        int r = dfs(root->right, maxPath);
        int ans = 1;
        if(l and root->val == root->left->val) ans += l;
        else l = 0;
        if(r and root->val == root->right->val) ans += r;
        else r = 0;
        maxPath = max(maxPath, ans);
        return max(l, r)+1;
    }
    int longestUnivaluePath(TreeNode* root) {
        int maxPath = 1;
        dfs(root, maxPath);
        return maxPath-1;
    }
};
