from leetcode import ListNode

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
            return None
        cur = head
        head = ListNode(0)
        head.next = cur
        par = head
        is_dup = False
        while cur.next != None:
            if cur.next.val == cur.val:
                cur.next = cur.next.next
                is_dup = True
            else:
                if is_dup:
                    par.next = cur.next
                    is_dup = False
                else:
                    par = par.next
                cur = cur.next
        if is_dup:
            par.next = None
        return head.next
