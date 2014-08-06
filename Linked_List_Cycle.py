# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:

    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        follower = head
        while head is not None and head.next is not None:
            follower = follower.next
            head = head.next.next
            if follower == head:
                return True
        return False
