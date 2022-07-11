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
    int ans{};
    
    tuple<int,int,int> dfs(TreeNode* root){
        if(!root) return {INT_MAX, INT_MIN, 0};
        int sum = root->val;
        auto [a, b, c] = dfs(root->left);
        auto [d, e, f] = dfs(root->right);
        if(b < sum and d > sum){
            a = min(a, sum);
            e = max(e, sum);
            sum += c + f;
            ans = max(ans, sum);
            return {a, e, sum};
        }
        return {INT_MIN, INT_MAX, 0};
    }
    
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
