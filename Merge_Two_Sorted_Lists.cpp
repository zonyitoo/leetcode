/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }

        ListNode *head, *pnt1, *pnt2;
        if (l1->val <= l2->val) {
            head = l1;
            pnt1 = l1->next;
            pnt2 = l2;
        } else {
            head = l2;
            pnt1 = l1;
            pnt2 = l2->next;
        }

        ListNode *curpnt = head;

        while (pnt1 != NULL && pnt2 != NULL) {
            if (pnt1->val <= pnt2->val) {
                curpnt->next = pnt1;
                pnt1 = pnt1->next;
            } else {
                curpnt->next = pnt2;
                pnt2 = pnt2->next;
            }

            curpnt = curpnt->next;
        }

        if (pnt1 != NULL) {
            curpnt->next = pnt1;
        } else if (pnt2 != NULL) {
            curpnt->next = pnt2;
        }

        return head;
    }
};
