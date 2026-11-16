# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        k = 0
        curr = head
        while curr:
            curr = curr.next
            k += 1

        remove_nth = k - n
        if remove_nth == 0:
            return head.next
        
        curr = head
        for i in range(k - 1):
            if (i + 1) == remove_nth:
                curr.next = curr.next.next
            curr = curr.next
        
        return head
