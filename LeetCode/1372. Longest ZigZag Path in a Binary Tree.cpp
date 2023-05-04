// Author: @AdarshGaur

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
    int ans = 0;

    pair<int,int> dfs(TreeNode* root){
        int left = 0, right = 0;
        if(root->left){
            right = dfs(root->left).first +1;
        }
        if(root->right){
            left = dfs(root->right).second +1;
        }
        ans = max({ans, left, right});
        return {left, right};
    }
    
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

