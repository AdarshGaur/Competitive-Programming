// Author : AdarshGaur

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *tail = head;
        map<Node* , Node*> mp;
        while(tail){
            mp[tail] = new Node(tail->val);
            tail = tail->next;
        }
        tail = head;
        while(tail){
            mp[tail]->random = mp[tail->random];
            mp[tail]->next = mp[tail->next];
            tail = tail->next;
        }
        return mp[head];
    }
};