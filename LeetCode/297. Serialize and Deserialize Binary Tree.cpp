// Author : @AdarshGaur

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N,";
        string s = to_string(root->val);
        s += "," + serialize(root->left) + serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        while(!data.empty()){
            int x = data.find(',');
            auto v = data.substr(0, x);
            q.push(v);
            data = data.substr(x+1);
        }
        return converter(q);
    }
    
    TreeNode* converter(queue<string>& q){
        auto v = q.front();
        q.pop();
        if(v == "N") return NULL;
        TreeNode* root = new TreeNode(stoi(v));
        root->left = converter(q);
        root->right = converter(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
