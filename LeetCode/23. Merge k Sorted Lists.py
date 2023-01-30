#Author: @AdarshGaur

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from queue import PriorityQueue

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pq = PriorityQueue()
        for i in range(len(lists)):
            if lists[i]:
                pq.put((lists[i].val, i))
        
        dummy = ListNode(0)
        head = dummy
        while not pq.empty():
            val, i = pq.get()
            head.next = ListNode(val)
            head = head.next
            if lists[i].next:
                lists[i] = lists[i].next
                pq.put((lists[i].val, i))
        
        return dummy.next
        
