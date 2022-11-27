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
    map<TreeNode*, int> mp;
    
    int best(TreeNode* cur){
        if(cur == NULL) return 0;
        if(mp.find(cur) != mp.end()) return mp[cur];
        
        int leftBest = 0, rightBest = 0;
        TreeNode *leftside = cur->left, *rightside = cur->right;
        if(leftside != NULL){
            TreeNode *L = leftside->left, *R = leftside->right;
            TreeNode *LR = NULL, *LL = NULL, *RL = NULL, *RR = NULL;
            if(L != NULL) LR = L->right, LL = L->left;
            if(R != NULL) RL = R->left, RR = R->right;
            leftBest += max(best(LR)+best(LL), best(L)) + max(best(R), best(RL) + best(RR));
        }
        if(rightside != NULL){
            TreeNode *L = rightside->left, *R = rightside->right;
            TreeNode *LR = NULL, *LL = NULL, *RL = NULL, *RR = NULL;
            if(L != NULL) LR = L->right, LL = L->left;
            if(R != NULL) RL = R->left, RR = R->right;
            rightBest += max(best(L), best(LR) + best(LL)) + max(best(R), best(RL) + best(RR));
        }
        return mp[cur] = max({leftBest + rightBest + cur->val, leftBest+best(cur->right), rightBest + best(cur->left)});
    }
    
    int rob(TreeNode* root) {
        return max(best(root), best(root->left)+best(root->right));
    }
};
