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
    int countNodes(TreeNode *root) {
        int count = this->isTreeComplete(root);
        if (count != -1) {
            // It is complete
            return count;
        }

        int left_cnt = this->countNodes(root->left);
        int right_cnt = this->countNodes(root->right);
        return left_cnt + right_cnt + 1;
    }

private:
    int isTreeComplete(TreeNode *root) {
        if (root == nullptr) return 0;

        TreeNode *left = root, *right = root;
        int count = 1;
        for (; left != nullptr && right != nullptr; left = left->left, right = right->right) {
            count <<= 1;
        }

        if (left != nullptr || right != nullptr) {
            return -1; // Not complete
        }

        return count - 1;
    }
};
