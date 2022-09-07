// Author : @AdarshGaur

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> t;
            for(int i=0; i<s; i++){
                Node* u = q.front();
                q.pop();
                t.push_back(u->val);
                for(Node* v: u->children){
                    if(v)
                        q.push(v);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};
