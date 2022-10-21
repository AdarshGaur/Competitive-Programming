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
    unordered_map<int,int> mp;
    
    TreeNode* build(vector<int>& postOrder, int l, int r, int& postLast){
        if(l > r) return NULL;
        TreeNode* node = new TreeNode(postOrder[postLast--]);
        int inIndx = mp[node->val];
        node->right = build(postOrder, inIndx+1, r, postLast);
        node->left = build(postOrder, l, inIndx-1, postLast);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(), postLast = n-1;
        for(int i=0; i<n; i++)
            mp[inorder[i]] = i;
        return build(postorder, 0, n-1, postLast);
    }
};
