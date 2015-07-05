#include "leetcode.hpp"

#include <vector>
using std::vector;
using std::move;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        vector<int> stack;
        dfs_solve(root, result, stack, 0, sum);
        return move(result);
    }

private:
    void dfs_solve(TreeNode *root, vector<vector<int>> &result,
                   vector<int> &stack, int cursum, int target) {
        if (root == nullptr) {
            return;
        }

        stack.push_back(root->val);
        int newsum = cursum + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (newsum == target) {
                result.push_back(stack);
            }
        } else {
            if (root->left != nullptr) {
                dfs_solve(root->left, result, stack, newsum, target);
            }
            if (root->right != nullptr) {
                dfs_solve(root->right, result, stack, newsum, target);
            }
        }
        stack.pop_back();
    }
};

