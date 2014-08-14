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
    ListNode *swapPairs(ListNode *head) {
        ListNode *current = head, *last = nullptr;

        while (current != nullptr && current->next != nullptr) {
            ListNode *fast = current->next->next;
            if (last != nullptr) {
                last->next = current->next;
            } else {
                head = current->next;
            }
            current->next->next = current;
            current->next = fast;

            last = current;
            current = fast;
        }

        return head;
    }
};

