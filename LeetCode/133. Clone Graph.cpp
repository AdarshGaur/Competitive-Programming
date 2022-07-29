// Author : @AdarshGaur

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> hash;
    
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(!hash.count(node)){
            hash[node] = new Node(node->val, {});
            for(auto &neigh: node->neighbors){
                hash[node]->neighbors.push_back(cloneGraph(neigh));
            }
        }
        return hash[node];
    }
};
