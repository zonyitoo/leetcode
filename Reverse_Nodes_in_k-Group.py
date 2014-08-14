from leetcode import ListNode

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:

    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def reverseKGroup(self, head, k):
        fakehead = ListNode(0)
        fakehead.next = head
        cur = fakehead
        while cur is not None and cur.next is not None:
            slow, fast = cur.next, cur.next.next
            for _ in xrange(k - 1):
                if fast is None:
                    # Not enough elements
                    # Recover list
                    cur.next.next = fast
                    cur.next = slow
                    slow, fast = cur.next, cur.next.next
                    while fast is not None:
                        next = fast.next
                        fast.next = slow
                        slow = fast
                        fast = next
                    cur.next.next = fast
                    cur.next = slow
                    return fakehead.next
                next = fast.next
                fast.next = slow
                slow = fast
                fast = next
            next = cur.next
            cur.next.next = fast
            cur.next = slow
            cur = next
        return fakehead.next
