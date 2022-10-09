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
    void dfs(TreeNode* root, int& val, int depth){
        if(!root) return;
        if(depth == 1){
            TreeNode* L = new TreeNode(val);
            TreeNode* R = new TreeNode(val);
            L->left = root->left;
            R->right = root->right;
            root->left = L;
            root->right = R;
        }else{
            dfs(root->left, val, depth-1);
            dfs(root->right, val, depth-1);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val, root, NULL);
            return node;
        }
        dfs(root, val, depth-1);
        return root;
    }
};
