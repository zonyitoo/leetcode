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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr)
            return head;
        ListNode *cur = head->next, *last = head;
        while (cur != nullptr) {
            if (cur->val == last->val) {
                last->next = cur->next;
                delete cur;
                cur = last->next;
            } else {
                last = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
