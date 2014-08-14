# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:

    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        if head is None:
            return None

        slow = None
        fast = head
        while n != 1:
            if fast.next is None:
                return head
            fast = fast.next
            n -= 1

        while fast.next is not None:
            if slow is not None:
                slow = slow.next
            else:
                slow = head
            fast = fast.next

        if slow is None:
            nxt = head.next
            head.next = None
            return nxt
        else:
            slow.next = slow.next.next
            return head
