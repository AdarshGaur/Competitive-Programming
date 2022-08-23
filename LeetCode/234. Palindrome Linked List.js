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
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let cur = head, fast = head.next
    while(fast && fast.next){
        fast = fast.next.next
        cur = cur.next
    }
    let prev = null, next = null
    cur = cur.next
    while(cur){
        next = cur.next
        cur.next = prev
        prev = cur
        cur = next
    }
    cur = prev
    while(cur){
        if(head.val != cur.val)
            return false;
        head = head.next
        cur = cur.next
    }
    return true
};
