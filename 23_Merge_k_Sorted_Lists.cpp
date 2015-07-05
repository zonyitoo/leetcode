#include "leetcode.hpp"

#include <vector>
using std::vector;
#include <queue>
using std::priority_queue;

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
    ListNode *mergeKLists(const vector<ListNode *> &lists) {
        ListNode *head = nullptr;
        ListNode **newlistcur = &head;

        priority_queue<ListNode *, vector<ListNode *>, ListCompare> q;
        for (auto node : lists) {
            if (node != nullptr) {
                q.push(node);
            }
        }

        while (!q.empty()) {
            ListNode *cur = q.top();
            q.pop();

            *newlistcur = cur;
            newlistcur = &(*newlistcur)->next;
            cur = cur->next;
            if (cur != nullptr) {
                q.push(cur);
            }
        }

        return head;
    }
private:
    class ListCompare {
    public:
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
};
