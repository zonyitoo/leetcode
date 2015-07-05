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
    bool hasCycle(ListNode *head) {
        ListNode *follower = head;
        while (head != nullptr && head->next != nullptr) {
            follower = follower->next;
            head = head->next->next;

            if (follower == head)
                return true;
        }
        return false;
    }
};
