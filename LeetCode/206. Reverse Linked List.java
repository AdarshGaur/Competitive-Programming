/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode curNode = head;
        ListNode lastNode = null;
        while(curNode != null){
            ListNode tempNode = curNode.next;
            curNode.next = lastNode;
            lastNode = curNode;
            curNode = tempNode;
        }
        return lastNode;
    }
}

