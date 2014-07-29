
#include <iostream>
using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast->next != nullptr) {
            fast = fast->next;
            if (fast->next != nullptr) {
                fast = fast->next;
            } else {
                break;
            }
            slow = slow->next;
        }
        ListNode *right = slow->next;
        slow->next = nullptr;

        ListNode *sortedLeft = sortList(head);
        ListNode *sortedRight = sortList(right);
        return mergeSortedList(sortedLeft, sortedRight);
    }

private:
    ListNode *mergeSortedList(ListNode *a, ListNode *b) {
        ListNode *head = nullptr;
        ListNode **cur = &head;
        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                *cur = a;
                cur = &a->next;
                a = a->next;
            } else {
                *cur = b;
                cur = &b->next;
                b = b->next;
            }
        }

        while (a != nullptr) {
            *cur = a;
            cur = &a->next;
            a = a->next;
        }

        while (b != nullptr) {
            *cur = b;
            cur = &b->next;
            b = b->next;
        }

        return head;
    }
};

int main() {
    int initvals[] = {1, 3, 5, 7, 2, 4, 6, 8};
    ListNode *head = nullptr;
    ListNode **cur = &head;
    for (auto &val : initvals) {
        *cur = new ListNode(val);
        cur = &(*cur)->next;
    }

    head = Solution().sortList(head);

    while (head != nullptr) {
        cout << head->val << " " ;
        head = head->next;
    }
    cout << endl;
    return 0;
}
