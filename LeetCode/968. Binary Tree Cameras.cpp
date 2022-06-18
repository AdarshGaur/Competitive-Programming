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
    int need_camera = 0, have_camera = 1, covered_by_camera = 2;
    int dfs(TreeNode* root, int& cam){
        if(!root) return covered_by_camera;
        int l = dfs(root->left, cam);
        int r = dfs(root->right, cam);
        if(l == need_camera or r == need_camera){
            cam++;
            return have_camera;
        }
        if(l == have_camera or r == have_camera)
            return covered_by_camera;
        return need_camera;
    }
    
    int minCameraCover(TreeNode* root) {
        int cam = 0;
        return (dfs(root, cam) == need_camera ? cam+1: cam);
    }
};
