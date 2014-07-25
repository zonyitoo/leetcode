# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    # @param head, a ListNode
    # @return a ListNode

    def deleteDuplicates(self, head):
        if head is None:
            return head

        cur, last = head.next, head
        while cur is not None:
            if cur.val == last.val:
                last.next = cur.next
            else:
                last = cur
            cur = cur.next
        return head
