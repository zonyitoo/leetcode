#include "leetcode.hpp"

#include <stack>
using std::stack;

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
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }

        stack<ListNode *> nodes;
        ListNode *cur = head;
        while (cur != nullptr) {
            nodes.push(cur);
            cur = cur->next;
        }

        cur = head;
        for (;;) {
            ListNode *front = nodes.top();
            nodes.pop();

            if (front == cur || front == cur->next) {
                front->next = nullptr;
                break;
            }

            front->next = cur->next;
            cur->next = front;

            cur = cur->next->next;
        }
    }
};

