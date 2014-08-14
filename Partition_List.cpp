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
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *cur = head;
        ListNode *lhead = nullptr, **lpnt = &lhead;
        ListNode *ghead = nullptr, **gpnt = &ghead;
        while (cur != nullptr) {
            if (cur->val < x) {
                *lpnt = cur;
                lpnt = &cur->next;
            } else {
                *gpnt = cur;
                gpnt = &cur->next;
            }
            cur = cur->next;
        }
        *lpnt = ghead;
        *gpnt = nullptr;

        return lhead;
    }
};
