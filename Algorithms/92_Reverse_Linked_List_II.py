from leetcode import ListNode

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:

    # @param head, a ListNode
    # @param m, an integer
    # @param n, an integer
    # @return a ListNode
    def reverseBetween(self, head, m, n):
        fakehead = ListNode(0)
        fakehead.next = head
        first = fakehead
        n -= m
        while m != 1:
            first = first.next
            m -= 1
        if first is None or first.next is None:
            return head
        slow, fast = first.next, first.next.next
        while n > 0:
            next = fast.next
            fast.next = slow
            slow = fast
            fast = next
            n -= 1
        first.next.next = fast
        first.next = slow
        return fakehead.next
