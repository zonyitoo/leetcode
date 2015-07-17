#include "leetcode.hpp"

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

        TreeNode *ans = nullptr;
        this->solve(root, p, q, 0, &ans);
        return ans;
    }

private:
    int solve(TreeNode *root, TreeNode *p, TreeNode *q, int found, TreeNode **ans) {
        if (root == nullptr) return found;

        if (root == p) ++found;
        if (root == q) ++found;

        if (found == 2) {
            *ans = root;
            return found;
        }

        int prev_found = found;
        found = solve(root->left, p, q, found, ans);

        if (found == 2) {
            if (prev_found == 1) {
                *ans = root;
                return found;
            }
            return found;
        }

        prev_found = found;
        found = solve(root->right, p, q, found, ans);

        if (found == 2 && prev_found == 1) {
            *ans = root;
        }

        return found;
    }
};
