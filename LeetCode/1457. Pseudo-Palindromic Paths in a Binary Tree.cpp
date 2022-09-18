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
    
    int check(vector<int>& f){
        int even{}, odd{};
        for(int &i: f){
            if(i&1) odd++;
            else even++;
        }
        return odd <= 1;
    }
    
    void dfs(TreeNode* root, vector<int>& f, int& ans){
        f[root->val]++;
        if(!root->left and !root->right){
            ans += check(f);
            f[root->val]--;
            return ;
        }
        if(root->left) dfs(root->left, f, ans);
        if(root->right) dfs(root->right, f, ans);
        f[root->val]--;
        return;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> frq(10, 0);
        int ans = 0;
        dfs(root, frq, ans);
        return ans;
    }
};
