// Author : @AdarshGaur

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(target->val == cloned->val) return cloned;
        queue<TreeNode*> q;
        q.push(cloned);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            if(u->left){
                if(u->left->val == target->val) return u->left;
                q.push(u->left);
            }
            if(u->right){
                if(u->right->val == target->val) return u->right;
                q.push(u->right);
            }
        }
        return NULL;
    }
};
