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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxD(root, diameter);
        return diameter;
    }
    int maxD(TreeNode* cur, int &diameter){
        if(!cur)
            return 0;
        int ld = maxD(cur->left, diameter);
        int rd = maxD(cur->right, diameter);
        diameter = max(diameter, ld + rd);
        return 1 + max(ld, rd);
    }
};
