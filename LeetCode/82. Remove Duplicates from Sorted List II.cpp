// Author : AdarshGaur

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *tail = dummy;
        while( tail != NULL){
            if(tail->next && tail->next->next &&
               tail->next->val == tail->next->next->val){
                int v = tail->next->val;
                while(tail->next && tail->next->val == v){
                    tail->next = tail->next->next;
                }
            }else{
                tail = tail->next;
            }
        }
        return dummy->next;
    }
};