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
    int maxPathSum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int sum = root->val;
        int right = solve(root->right);
        if (right >= 0) {
            sum += right;
            int left = solve(root->left);
            if (left >= 0) {
                sum += left;
            }
        }
        return sum;
    }

private:
    int solve(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->right != nullptr) {
            return solve(root->right) + root->val;
        } else if (root->left != nullptr) {
            int left = solve(root->left);
            if (left < 0) {
                return root->val;
            } else {
                return root->val + left;
            }
        } else {
            return root->val;
        }
    }
};
