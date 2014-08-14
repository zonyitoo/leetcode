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
    ListNode *insertionSortList(ListNode *head) {
        ListNode tmphead(0);
        tmphead.next = head;

        ListNode *curpnt = &tmphead;
        ListNode *mvpnt = &tmphead;
        while (mvpnt->next != nullptr) {
            ListNode *nminpnt = mvpnt;
            mvpnt = mvpnt->next;
            while (mvpnt->next != nullptr) {
                if (mvpnt->next->val < nminpnt->next->val) {
                    nminpnt = mvpnt;
                }
                mvpnt = mvpnt->next;
            }

            ListNode *minpnt = nminpnt->next;
            nminpnt->next = minpnt->next;
            minpnt->next = curpnt->next;
            curpnt->next = minpnt;
            curpnt = minpnt;
            mvpnt = curpnt;
        }

        return tmphead.next;
    }
};
