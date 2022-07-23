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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(0), *cur = dummy, *part;
        dummy->next = head;
        while(cur->next != NULL and cur->next->val < x)
            cur = cur->next;
        part = cur->next;
        while(part != NULL and part->next != NULL){
            if(part->next->val < x){
                ListNode *t = part->next;
                part->next = t->next;
                t->next = cur->next;
                cur->next = t;
                cur = cur->next;
            }else{
                part = part->next;
            }
        }
        return dummy->next;
    }
};
