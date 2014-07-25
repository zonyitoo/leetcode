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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (isSameNode(p, q)) {
            if (p != NULL && q != NULL) {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
            return true;
        }
        return false;
    }

    bool isSameNode(TreeNode *a, TreeNode *b) {
        if (a != NULL && b != NULL) {
            return a->val == b->val;
        }
        return a == NULL && b == NULL;
    }

};
