#include "leetcode.hpp"

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (isSameNode(p, q)) {
            if (p != nullptr && q != nullptr) {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
            return true;
        }
        return false;
    }

    bool isSameNode(TreeNode *a, TreeNode *b) {
        if (a != nullptr && b != nullptr) {
            return a->val == b->val;
        }
        return a == nullptr && b == nullptr;
    }

};
