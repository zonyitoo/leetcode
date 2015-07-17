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
    bool isPalindrome(ListNode *head) {
        // If it is empty, return true
        if (head == nullptr) return true;

        // Find the middle node
        ListNode *mid, *ptr;
        mid = ptr = head;
        while (ptr != nullptr && ptr->next != nullptr) {
            mid = mid->next;
            ptr = ptr->next->next;
        }

        // Reverse the [mid, last) part
        ListNode *prev, *cur, *next;
        prev = mid;
        cur = prev->next;
        mid->next = nullptr;
        while (cur != nullptr) {
            next = cur->next;

            cur->next = prev;

            prev = cur;
            cur = next;
        }

        // Determine whether it is palindrome
        ListNode *left = head, *right = prev;
        while (left != nullptr && right != nullptr) {
            if (left->val != right->val) {
                return false;
            }

            left = left->next;
            right = right->next;
        }

        return true;
    }
};
