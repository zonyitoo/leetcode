#include "leetcode.hpp"

#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return nullptr;
        if (p == q) return p;

        if (p->val > q->val) {
            std::swap(p, q);
        }

        return this->solve(root, p, q);
    }

private:
    TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return nullptr;

        if (root->val < p->val) {
            return solve(root->right, p, q);
        } else if (root->val >= p->val && root->val <= q->val) {
            return root;
        } else {
            return solve(root->left, p, q);
        }
    }
};
