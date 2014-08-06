#ifndef NULL
#define NULL 0
#endif

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode *cur = head->next, *last = head;
        while (cur != NULL) {
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
