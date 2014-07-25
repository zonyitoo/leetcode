# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    # @param two ListNodes
    # @return a ListNode

    def mergeTwoLists(self, l1, l2):
        if l1 is None:
            return l2
        elif l2 is None:
            return l1

        head, pnt1, pnt2 = (l1, l1.next, l2) if l1.val <= l2.val else (l2, l1, l2.next)
        curpnt = head

        while pnt1 is not None and pnt2 is not None:
            if pnt1.val <= pnt2.val:
                curpnt.next = pnt1
                pnt1 = pnt1.next
            else:
                curpnt.next = pnt2
                pnt2 = pnt2.next
            curpnt = curpnt.next

        if pnt1 is not None:
            curpnt.next = pnt1
        elif pnt2 is not None:
            curpnt.next = pnt2

        return head
