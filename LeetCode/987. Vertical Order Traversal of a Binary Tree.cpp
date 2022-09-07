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
    
    void findDiameter(TreeNode* root, int pos, int& left, int& right){
        if(!root) return;
        left = min(left, pos);
        right = max(right, pos);
        findDiameter(root->left, pos-1, left, right);
        findDiameter(root->right, pos+1, left, right);
    }
    
    void dfs(TreeNode* root, vector<vector<pair<int,int>>>& ans, int pos, int level){
        if(!root) return;
        ans[pos].push_back({level ,root->val});
        dfs(root->left, ans, pos-1, level+1);
        dfs(root->right, ans, pos+1, level+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // first find the diameter
        int left=0, right=0;
        findDiameter(root, 0, left, right);
        
        // evaluate the length of returning vector and store the node values with their level
        int len = right - left +1;
        vector<vector<pair<int,int>>> store(len);
        
        // simple dfs;
        dfs(root, store, -left, 0);
        vector<vector<int>> ans;
        for(auto &v: store){
            sort(v.begin(), v.end());
            vector<int> t;
            for(auto [level, val]: v)
                t.emplace_back(val);
            ans.emplace_back(t);
        }
        return ans;
    }
};
