#include "leetcode.hpp"

#include <queue>
using std::queue;
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }

        queue<TreeLinkNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeLinkNode *cur = q.front();
            q.pop();
            if (cur->left != nullptr) {
                cur->left->next = cur->right;
                q.push(cur->left);
            }
            if (cur->next != nullptr) {
                TreeLinkNode *next = cur->next;
                while (next != nullptr && next->left == nullptr && next->right == nullptr)
                    next = next->next;
                if (next != nullptr) {
                    next = (next->left != nullptr) ? next->left : next->right;
                    if (cur->right != nullptr) {
                        cur->right->next = next;
                    } else if (cur->left != nullptr) {
                        cur->left->next = next;
                    }
                }
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
    }
};
