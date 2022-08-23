// Author : @AdarshGaur

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteMiddle = function(head) {
    if(head.next == null)
        return null
    
    let tortoise = head, hare = head.next, prev = null
    while(hare != null && hare.next != null)
        prev = tortoise, tortoise = tortoise.next, hare = hare.next.next
    
    let left = tortoise, right = tortoise.next.next
    if(hare == null)
        left = prev, right = tortoise.next
    
    left.next = null
    left.next = right
    
    return head
};
