#include "leetcode.hpp"

#include <iostream>

#define ABS(value) (((value) > 0) ? (value) : (0 - (value)))

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
    bool isBalanced(TreeNode *root) {
        if (root == nullptr)
            return true;
        int dummy;
        return treeDepthTraversal(root, dummy);
    }

private:
    bool treeDepthTraversal(TreeNode *root, int &depth) {
        if (root == nullptr) {
            depth = 0;
            return true;
        }
        int ldepth, rdepth;
        if (!treeDepthTraversal(root->left, ldepth)) {
            return false;
        }
        if (!treeDepthTraversal(root->right, rdepth)) {
            return false;
        }
        if (ABS(ldepth - rdepth) > 1) {
            return false;
        }
        depth = 1 + ((ldepth > rdepth) ? ldepth : rdepth);
        return true;
    }
};

