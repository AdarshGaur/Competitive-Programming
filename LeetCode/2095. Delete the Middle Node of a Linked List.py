# Author : @AdarshGaur

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head.next == None: return None
        
        tortoise = head
        hare = head.next
        prev = None
        
        while hare != None and hare.next != None:
            hare = hare.next.next
            prev = tortoise
            tortoise = tortoise.next
        
        left = tortoise
        right = tortoise.next.next
        
        if hare == None:
            left = prev
            right = tortoise.next
        
        left.next = right
        return head
        
