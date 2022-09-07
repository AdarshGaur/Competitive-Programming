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
    
    bool dfs(TreeNode* root){
        if(!root) return 0;
        if(!dfs(root->left)) root->left = NULL;
        if(!dfs(root->right)) root->right = NULL;
        if(root->val == 0 and !root->right and !root->left) return false;
        return true;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* dummy = new TreeNode(1, root, NULL);
        if(!dfs(dummy->left)) return NULL;
        return dummy->left;
    }
};
