#include "leetcode.hpp"

#include <vector>
#include <climits>
using std::vector;

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
    void recoverTree(TreeNode *root) {

    }

private:
    void dfs_solve(vector<TreeNode *> &result, TreeNode *root, int mini, int maxi, bool is_left) {
        if (result.size() == 2 || root == nullptr) {
            return;
        }

        if (is_left) {
            if (root->val >= mini) {
                result.push_back(root);
            }
        } else {

        }
    }
};
