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
    
    void dfs(TreeNode* root, int level, vector<double>& ans, vector<int>& cnt){
        if(!root) return;
        if(level == ans.size()){
            ans.push_back(0);
            cnt.push_back(0);
        }
        ans[level] += root->val;
        cnt[level] += 1;
        
        dfs(root->left, level+1, ans, cnt);
        dfs(root->right, level+1, ans, cnt);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> cnt(1, 0);
        vector<double> ans(1, 0);
        dfs(root, 0, ans, cnt);
        for(int i=0; i<ans.size(); i++)
            ans[i] = (ans[i] / cnt[i]);
        return ans;
    }
};
