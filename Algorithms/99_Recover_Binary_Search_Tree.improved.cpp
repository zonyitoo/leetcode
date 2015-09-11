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
    void recoverTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        TreeNode * r1 = nullptr, * r2 = nullptr, * pre_order = nullptr;

        TreeNode * cur = root, * pre = nullptr;
        // Morris Traversal
        // http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
        while (cur != nullptr) {
            if (cur->left == nullptr) {

                // Current is the current inorder result

                if (pre_order != nullptr) {
                    if (r1 == nullptr) {
                        if (cur->val < pre_order->val) {
                            r1 = pre_order;
                        }
                    } else if (r2 == nullptr) {
                        if (cur->val > r1->val) {
                            r2 = pre_order;
                        }
                    }
                }

                pre_order = cur;
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right != nullptr && pre->right != cur) {
                    pre = pre->right;
                }

                if (pre->right == nullptr) {
                    pre->right = cur;
                    cur = cur->left;
                } else {

                    if (r1 == nullptr) {
                        if (cur->val < pre_order->val) {
                            r1 = pre_order;
                        }
                    } else if (r2 == nullptr) {
                        if (cur->val > r1->val) {
                            r2 = pre_order;
                        }
                    }
                    pre_order = cur;

                    pre->right = nullptr;
                    cur = cur->right;
                }
            }
        }

        if (r2 == nullptr) {
            r2 = pre_order;
        }

        if (r1 != nullptr && r2 != nullptr) {
            std::swap(r1->val, r2->val);
        }
    }
};
