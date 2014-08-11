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
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *cur = head;
        ListNode *lhead = nullptr, **lpnt = &lhead;
        ListNode *ghead = nullptr, **gpnt = &ghead;
        while (cur != nullptr) {
            if (cur->val < x) {
                *lpnt = cur;
                lpnt = &cur->next;
            } else {
                *gpnt = cur;
                gpnt = &cur->next;
            }
            cur = cur->next;
        }
        *lpnt = ghead;
        *gpnt = nullptr;

        return lhead;
    }
};

int main(int argc, char **argv) {
    Solution s;
    int testlist[] = {1, 4, 3, 2, 5, 2};
    ListNode *head = nullptr, *cur = nullptr;
    for (auto &item : testlist) {
        if (head == nullptr) {
            head = new ListNode(item);
            cur = head;
        } else {
            cur->next = new ListNode(item);
            cur = cur->next;
        }
    }
    cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    ListNode *nhead = s.partition(head, 3);
    cur = nhead;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}
