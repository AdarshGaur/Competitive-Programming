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
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    let tortoise = head, hare = head.next
    while(hare && hare.next)
        tortoise = tortoise.next, hare = hare.next.next
    
    // reverse List onwards mid
    let prev = null, cur = tortoise, next = null
    while(cur != null){
        next = cur.next, cur.next = prev
        prev = cur, cur = next
    }
    
    // merge both the lists
    let tail = prev, tnext = null
    while(head && tail){
        next = head.next, head.next = tail
        
        tnext = tail.next, tail.next = next
        head = next, tail = tnext
    }
};
