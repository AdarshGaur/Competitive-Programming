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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0), *prev = dummy, *cur;
        dummy->next = head;
        for(int i=0; i<left-1; i++){
            prev = prev->next;
        }
        cur = prev->next;
        for(int i=0; i<right-left; i++){
            ListNode *t = prev->next;
            prev->next = cur->next;
            cur->next = cur->next->next;
            prev->next->next = t;
        }
        return dummy->next;
    }
};
