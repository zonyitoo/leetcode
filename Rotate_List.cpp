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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        } else if (k == 0) {
            return head;
        }
        ListNode *fast = head;
        while (--k) {
            fast = fast->next != nullptr ? fast->next : head;
        }

        ListNode *newhead = head;
        while (fast != nullptr && fast->next != nullptr) {
            ListNode *newheadnext = newhead->next, *newfast = fast->next;
            if (fast->next->next == nullptr) {
                newhead->next = nullptr;
            }
            newhead = newheadnext;
            fast = newfast;
        }

        if (newhead != head)
            fast->next = head;
        return newhead;
    }
};

