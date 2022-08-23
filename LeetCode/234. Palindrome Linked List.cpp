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
    
    ListNode* findMid(ListNode* head){
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode *cur = head, *prev=NULL, *next=NULL;
        while(cur != NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return true;
        
        // find mid
        ListNode* mid = findMid(head);
        
        // reverse list after mid point
        ListNode* t = mid->next;
        mid -> next = reverseList(t);
        mid = mid->next;
        
        // check for equality for palindromes
        while(mid != NULL){
            if(mid->val != head->val)
                return false;
            mid = mid->next;
            head = head->next;
        }
        return true;
    }
};
