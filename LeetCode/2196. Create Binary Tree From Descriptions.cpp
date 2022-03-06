// Author : AdarshGaur

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> l, r;
        unordered_set<int> s;
        for(auto v: descriptions){
            s.insert(v[0]);
        }
        for(auto v: descriptions){
            if(s.find(v[1]) != s.end()){
                s.erase(s.find(v[1]));
            }
            if(v[2] == 1){
                l[v[0]] = v[1];
            }else{
                r[v[0]] = v[1];
            }
        }
        if(s.empty()) return NULL;
        TreeNode* root = new TreeNode(*s.begin());
        deque<TreeNode* > q;
        q.push_back(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop_front();
            if(l.count(node->val) != 0){
                int left_val = l[node->val];
                TreeNode* left_child = new TreeNode(left_val);
                node->left = left_child;
                q.push_back(left_child);
            }
            if(r.count(node->val) != 0){
                int right_val = r[node->val];
                TreeNode* right_child = new TreeNode(right_val);
                node->right = right_child;
                q.push_back(right_child);
            }
        }
        return root;
    }
};

