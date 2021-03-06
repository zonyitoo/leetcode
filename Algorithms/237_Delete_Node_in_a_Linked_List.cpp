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
    void deleteNode(ListNode *const node) {
        ListNode *next = node->next;

        node->next = next->next;
        node->val = next->val;

        delete next;
    }
};
