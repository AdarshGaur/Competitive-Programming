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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int hLeft = 0, hRight = 0;
        TreeNode *l = root, *r = root;
        while(l != NULL){
            hLeft++;
            l = l->left;
        }
        while(r != NULL){
            hRight++;
            r = r->right;
        }
        
        if(hLeft == hRight)
            return (1 << hLeft) -1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
