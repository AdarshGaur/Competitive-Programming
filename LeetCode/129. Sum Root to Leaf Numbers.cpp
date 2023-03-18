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
    int sumNumbers(TreeNode* root, string cur="") {
        if(!root) return 0;
        cur += to_string(root->val);
        if(root->left == NULL and root->right == NULL){
            return stoi(cur);
        }
        return sumNumbers(root->left, cur) + sumNumbers(root->right, cur);
    }
};

