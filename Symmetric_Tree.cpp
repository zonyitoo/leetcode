#include <queue>
using std::queue;
#include <deque>
using std::deque;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

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
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode *> leftq, rightq;
        leftq.push(root->left);
        rightq.push(root->right);
        while (!leftq.empty() && !rightq.empty()) {
            TreeNode *left = leftq.front();
            leftq.pop();
            TreeNode *right = rightq.front();
            rightq.pop();
            if (left != nullptr && right != nullptr) {
                if (left->val != right->val) {
                    return false;
                }
                leftq.push(left->left);
                leftq.push(left->right);
                rightq.push(right->right);
                rightq.push(right->left);
            } else if (left == nullptr && right == nullptr) {
                // Do nothing
            } else {
                return false;
            }
        }

        return true;
    }
};
