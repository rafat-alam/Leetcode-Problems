# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        last = head
        curr = head.next
        sum = 0
        while curr:
            if curr.val == 0:
                last.next = curr
                last = curr
                last.val = sum
                sum = 0
            else:
                sum += curr.val
            curr = curr.next
        
        return head.next