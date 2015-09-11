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

        TreeNode * r1 = nullptr, * r2 = nullptr, * pre = nullptr;
        this->findInvalid(root, pre, r1, r2);


        if (r2 == nullptr) {
            r2 = pre;
        }

        cout << r1->val << " " << r2->val << " " << pre->val << endl;

        if (r1 != nullptr && r2 != nullptr) {
            std::swap(r1->val, r2->val);
        }
    }

private:
    void findInvalid(TreeNode *const root, TreeNode *& pre, TreeNode *& r1, TreeNode *& r2) const {
        if (root == nullptr) return;

        if (root->left != nullptr) {
            this->findInvalid(root->left, pre, r1, r2);
        }

        if (pre != nullptr) {
            // Not the first one
            if (r1 == nullptr && pre->val > root->val) {
                r1 = pre;
            } else if (r1 != nullptr && r2 == nullptr && root->val > r1->val) {
                r2 = pre;
                return;
            }
        }

        pre = root;
        if (root->right != nullptr) {
            this->findInvalid(root->right, pre, r1, r2);
        }
    }
};
