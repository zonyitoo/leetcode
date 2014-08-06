
#ifndef NULL
#define NULL 0
#endif

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

#include <stack>
using std::stack;

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
    void reorderList(ListNode *head) {
        if (head == NULL) {
            return;
        }

        stack<ListNode *> nodes;
        ListNode *cur = head;
        while (cur != NULL) {
            nodes.push(cur);
            cur = cur->next;
        }

        cur = head;
        while (true) {
            ListNode *front = nodes.top();
            nodes.pop();

            if (front == cur || front == cur->next) {
                front->next = NULL;
                break;
            }

            front->next = cur->next;
            cur->next = front;

            cur = cur->next->next;
        }
    }
};

