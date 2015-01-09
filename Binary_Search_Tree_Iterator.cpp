#include "leetcode.hpp"

#include <stack>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root)
        : current(root) {
        while (current != nullptr && current->left != nullptr) {
            level.push(current);
            current = current->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current != nullptr;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *ret = current;
        if (current->right != nullptr) {
            current = current->right;
            while (current->left != nullptr) {
                level.push(current);
                current = current->left;
            }
        } else {
            if (level.empty()) {
                current = nullptr;
            } else {
                current = level.top();
                level.pop();
            }
        }

        return ret->val;
    }

private:
    stack<TreeNode *> level;
    TreeNode *current;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
