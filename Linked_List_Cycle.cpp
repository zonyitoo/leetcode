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
    bool hasCycle(ListNode *head) {
        ListNode *follower = head;
        while (head != NULL && head->next != NULL) {
            follower = follower->next;
            head = head->next->next;

            if (follower == head)
                return true;
        }
        return false;
    }
};
