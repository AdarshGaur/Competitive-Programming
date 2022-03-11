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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k or !head) return head;
        int l = 1;
        ListNode *last = head, *tail = head;
        while(tail->next){
            l++;
            tail = tail->next;
            last = tail;
        }
        last->next = head;
        k %= l;
        tail = head;
        for(int i=1; i < l-k; i++){
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};
