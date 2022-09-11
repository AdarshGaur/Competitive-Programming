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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 1});
        while(!q.empty()){
            int first = q.front().second;
            int last = q.back().second;            
            maxWidth = max(maxWidth, last - first +1);
            
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto [node, pos] = q.front();
                q.pop();
                
                if(node->left)
                    q.push({node->left, pos*2 - first});
                
                if(node->right)
                    q.push({node->right, pos*2 +1 - first});
            }
        }
        return maxWidth;
    }
};
