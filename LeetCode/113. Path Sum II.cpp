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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int& target, vector<int>& t){
        t.push_back(root->val);
        target -= root->val;
        if(!root->left and !root->right and target == 0)
            ans.push_back(t);
        if(root->left)
            dfs(root->left, target, t);
        if(root->right)
            dfs(root->right, target, t);
        t.pop_back();
        target += root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        vector<int> t;
        dfs(root, targetSum, t);
        return ans;
    }
};
