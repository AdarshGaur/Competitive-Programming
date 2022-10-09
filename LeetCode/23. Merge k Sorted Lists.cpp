// Author : @AdarshGaur

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<>> pq;
        for(auto &list : lists){
            if(list != NULL){
                pq.push({list->val, list});
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(!pq.empty()){
            auto [v, p] = pq.top();
            pq.pop();
            
            head->next = p;
            p = p->next;
            if(p != NULL)
                pq.push({p->val, p});
            head = head->next;
        }
        return dummy->next;
    }
};
