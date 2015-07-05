#include "leetcode.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        __convert(&root->left, head, slow);
        __convert(&root->right, slow->next, nullptr);
        return root;
    }

private:
    void __convert(TreeNode **root, ListNode *beg, ListNode *end) {
        if (beg == end) {
            return;
        }
        ListNode *slow = beg, *fast = beg;
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }

        *root = new TreeNode(slow->val);
        __convert(&(*root)->left, beg, slow);
        __convert(&(*root)->right, slow->next, end);
    }
};
