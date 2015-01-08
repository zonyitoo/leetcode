#include "leetcode.hpp"

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        if (headA == headB) return headA;

        ListNode *ptrBeginB = headB,
                  *ptrCenterB = headB,
                   *ptrTailB = headB;
        while (ptrTailB->next != nullptr) {
            ptrCenterB = ptrCenterB->next;
            ptrTailB = ptrTailB->next;
            if (ptrTailB->next != nullptr) {
                ptrTailB = ptrTailB->next;
            }
        }

        while (true) {
            bool found = false;
            for (ListNode *ptrA = headA; ptrA != nullptr; ptrA = ptrA->next) {
                if (ptrA == ptrBeginB) {
                    return ptrA;
                }

                if (ptrA == ptrTailB) {
                    ptrBeginB = ptrCenterB;
                    found = true;
                    break;
                } else if (ptrA == ptrCenterB) {
                    ptrTailB = ptrCenterB;
                    found = true;
                    break;
                }
            }

            if (!found) break;

            ListNode *ptrB = ptrCenterB = ptrBeginB;
            while (ptrB != ptrTailB) {
                ptrCenterB = ptrCenterB->next;
                ptrB = ptrB->next;
                if (ptrB != ptrTailB) {
                    ptrB = ptrB->next;
                }
            }
        }

        return nullptr;
    }
};


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *ptrA = headA, *ptrB = headB;
        size_t lenA = 0, lenB = 0;
        for (; ptrA != nullptr; ptrA = ptrA->next, lenA++);
        for (; ptrB != nullptr; ptrB = ptrB->next, lenB++);
        if (ptrA != ptrB) return nullptr;

        ptrA = headA;
        ptrB = headB;
        if (lenA > lenB) {
            while (lenA-- > lenB) ptrA = ptrA->next;
        } else if (lenB > lenA) {
            while (lenB-- > lenA) ptrB = ptrB->next;
        }

        while (ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        return ptrA;
    }
};
