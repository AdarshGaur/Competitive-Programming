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
    
    void postOrderTraversal(TreeNode* root, vector<int>& postOrder){
        if(!root) return;
        postOrderTraversal(root->left, postOrder);
        postOrderTraversal(root->right, postOrder);
        postOrder.emplace_back(root->val);
        return ;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        postOrderTraversal(root, postOrder);
        return postOrder;
    }
};
