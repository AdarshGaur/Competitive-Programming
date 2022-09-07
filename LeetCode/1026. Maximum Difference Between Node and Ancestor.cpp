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
    
    pair<int,int> dfs(TreeNode* root, int& ans){
        if(!root->left and !root->right)
            return {root->val, root->val};
        int mn=1e5 +7, mx=-1;
        if(root->left){
            auto p = dfs(root->left, ans);
            mn = p.first, mx = p.second;
        }if(root->right){
            auto p = dfs(root->right, ans);
            mn = min(p.first, mn);
            mx = max(p.second, mx);
        }
        int cand = max(abs(root->val - mn), abs(root->val - mx));
        ans = max(ans, cand);
        return {min(mn, root->val), max(mx, root->val)};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
