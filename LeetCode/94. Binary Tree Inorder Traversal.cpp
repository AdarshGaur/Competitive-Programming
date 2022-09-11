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
    
    void inOrderTraversal(TreeNode* root, vector<int>& inOrder){
        if(!root) return;
        inOrderTraversal(root->left, inOrder);
        inOrder.emplace_back(root->val);
        inOrderTraversal(root->right, inOrder);
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        inOrderTraversal(root, inOrder);
        return inOrder;
    }
};
