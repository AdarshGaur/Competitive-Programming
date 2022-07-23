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
    
    bool isSame(TreeNode* left, TreeNode* right){
        if(!left and !right) return true;
        if((left and !right) or (!left and right) or left->val != right->val) return false;
        return isSame(left->right, right->left) and isSame(left->left, right->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            auto node1 = q.front();
            q.pop();
            auto node2 = q.front();
            q.pop();
            if(!node1 and !node2) continue;
            if((!node1 and node2) or (node1 and !node2) or (node1->val != node2->val)) return false;
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};
