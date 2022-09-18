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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int s = q.size();
            vector<TreeNode*> st;
            for(int i=0; i<s; i++){
                auto v = q.front();
                q.pop();
                if(level&1) st.emplace_back(v);
                if(v->left) q.push(v->left);
                if(v->right) q.push(v->right);
            }
            if(level &1){
                for(int i=0; i<s/2; i++){
                    swap(st[i]->val, st[s-1 -i]->val);
                }
            }
            level++;
        }
        return root;
    }
};
