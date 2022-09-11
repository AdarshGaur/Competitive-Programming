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
    
    void preOrderTraversal(TreeNode* root, vector<int>& preOrder){
        if(!root) return;
        preOrder.emplace_back(root->val);
        preOrderTraversal(root->left, preOrder);
        preOrderTraversal(root->right, preOrder);
        return;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        // preOrderTraversal(root, preOrder);
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur != NULL or !st.empty()){
            while(cur != NULL){
                preOrder.emplace_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return preOrder;
    }
};
