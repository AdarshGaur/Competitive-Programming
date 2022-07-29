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
    bool pos = true;
    
    int height(TreeNode* cur){
        if(!cur) return 0;
        int l = height(cur->left);
        int r = height(cur->right);
        if(abs(r-l) > 1)
            pos = false;
        return max(r, l)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        height(root);
        return pos;
    }
};
