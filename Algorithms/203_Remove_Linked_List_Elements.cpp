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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;

        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;

        ListNode* node = fake_head;
        while (node->next != nullptr) {
            if (node->next->val == val) {
                ListNode* next = node->next;
                node->next = next->next;
                delete next;
            } else {
                node = node->next;
            }
        }

        head = fake_head->next;
        delete fake_head;

        return head;
    }
};
