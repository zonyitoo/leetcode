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
    ListNode *swapPairs(ListNode *head) {
        ListNode *current = head, *last = NULL;

        while (current != NULL && current->next != NULL) {
            ListNode *fast = current->next->next;
            if (last != NULL) {
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

