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
            if (cur->next != nullptr && cur->right != nullptr) {
                cur->right->next = cur->next->left;
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
    }
};
