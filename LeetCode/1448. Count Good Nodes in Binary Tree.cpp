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
    
    void dfs(TreeNode* root, int& ans, int mx){
        if(!root) return;
        if(root->val >= mx){
            ans++;
            mx = root->val;
        }
        dfs(root->left, ans, mx);
        dfs(root->right, ans, mx);
    }
    
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, INT_MIN);
        return ans;
    }
};
