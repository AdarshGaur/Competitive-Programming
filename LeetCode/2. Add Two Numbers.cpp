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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(l1 || l2){
            int s = carry;
            if(l1){
                s += l1->val;
                l1 = l1->next;
            }
            if(l2){
                s += l2->val;
                l2 = l2->next;
            }
            carry = s/10;
            s %= 10;
            ListNode *t = new ListNode(s);
            cur->next = t;
            cur = cur->next;
        }
        if(carry){
            ListNode *t = new ListNode(1);
            cur->next = t;
        }
        return dummy->next;
    }
};