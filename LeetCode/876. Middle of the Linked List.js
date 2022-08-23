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
var middleNode = function(head) {
    let tortoise = head, hare = head.next
    while(hare != null && hare.next != null)
        tortoise = tortoise.next, hare = hare.next.next
    
    if(hare != null)
        tortoise = tortoise.next
    
    return tortoise
};
