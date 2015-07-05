#include "leetcode.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
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

        while (pnt1 != nullptr && pnt2 != nullptr) {
            if (pnt1->val <= pnt2->val) {
                curpnt->next = pnt1;
                pnt1 = pnt1->next;
            } else {
                curpnt->next = pnt2;
                pnt2 = pnt2->next;
            }

            curpnt = curpnt->next;
        }

        if (pnt1 != nullptr) {
            curpnt->next = pnt1;
        } else if (pnt2 != nullptr) {
            curpnt->next = pnt2;
        }

        return head;
    }
};
