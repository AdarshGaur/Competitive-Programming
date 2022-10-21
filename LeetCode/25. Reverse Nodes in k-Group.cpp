// Author: @AdarshGaur

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
    
    ListNode* reverseKGroup(ListNode* head, int k){
        ListNode* ksize = head;
        for(int i=0; i<k; i++){
            if(!ksize) return head;
            ksize = ksize->next;
        }
        
        int cnt = 0;
        ListNode *cur = head, *prev = NULL, *next = NULL;
        while(cnt < k){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cnt++;
        }
        
        if(cur){
            // head pointer will be moved to the end of the list
            head->next = reverseKGroup(cur, k);
        }
        return prev;
    }
    
//     // With Stack
//     ListNode* reverse(ListNode* head, int K){
//         ListNode* node = head->next;
//         stack<ListNode*> st;
//         int k = K;
//         while(k>0 and node != NULL){
//             st.push(node);
//             node = node->next;
//             k--;
//         }
        
//         if(k != 0) return head->next;
        
//         // the stack will have exactly k elements
//         node = head;
//         ListNode* last = st.top()->next;
//         while(!st.empty()){
//             ListNode* x = st.top();
//             st.pop();
//             node -> next = x;
//             node = node->next;
//         }
//         node->next = last;
//         node->next = reverse(node, K);
//         return head->next;
//     }
    
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* dummy = new ListNode(0, head);
//         return reverse(dummy, k);
//     }
};
