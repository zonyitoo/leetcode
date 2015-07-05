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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = cur->next;

        while (cur != nullptr) {
            cur->next = prev;
            prev = cur;
            cur = next;

            if (next != nullptr) {
                next = next->next;
            }
        }

        return prev;
    }
};
