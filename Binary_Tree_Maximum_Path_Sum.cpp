#include "leetcode.hpp"

#include <climits>
#include <algorithm>
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
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }

private:
    int solve(TreeNode *root, int &ans) {
        if (root == nullptr) {
            return INT_MIN;
        }

        ans = std::max(ans, root->val);

        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        } else if (root->left != nullptr && root->right == nullptr) {
            int tmp = root->val + solve(root->left, ans);
            ans = std::max(ans, tmp);
            return std::max(root->val, tmp);
        } else if (root->left == nullptr && root->right != nullptr) {
            int tmp = root->val + solve(root->right, ans);
            ans = std::max(ans, tmp);
            return std::max(root->val, tmp);
        }

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        ans = std::max(ans, root->val + std::max(left, right));
        ans = std::max(ans, root->val + left + right);
        return std::max(root->val, root->val + std::max(left, right));
    }
};
