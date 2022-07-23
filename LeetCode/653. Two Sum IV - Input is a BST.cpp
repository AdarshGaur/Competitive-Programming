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
    
    bool check(TreeNode* cur, TreeNode* taken, int& target){
        if(!cur) return false;
        if(cur->val == target and cur != taken) return true;
        if(cur->val < target) return check(cur->right, taken, target);
        return check(cur->left, taken, target);
    }
    
    bool dfs(TreeNode* root, TreeNode* cur, int& k){
        if(!cur) return false;
        int target = k - cur->val;
        return check(root, cur, target) or dfs(root, cur->left, k) or dfs(root, cur->right, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k);
    }
};
