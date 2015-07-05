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
    vector<TreeNode *> generateTrees(int n) {
        return __solve(1, n);
    }

private:
    vector<TreeNode *> __solve(int beg, int end) {
        vector<TreeNode *> result;
        if (beg > end) {
            result.push_back(nullptr);
            return move(result);
        }
        for (int i = beg; i <= end; ++i) {
            TreeNode *root = new TreeNode(i);
            vector<TreeNode *> left = __solve(beg, i - 1);
            vector<TreeNode *> right = __solve(i + 1, end);
            for (TreeNode *l : left) {
                for (TreeNode *r : right) {
                    root->left = l;
                    root->right = r;
                    result.push_back(deepcopy(root));
                }
            }
            delete root;
        }
        return move(result);
    }


    TreeNode *deepcopy(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode *nroot = new TreeNode(root->val);
        nroot->left = deepcopy(root->left);
        nroot->right = deepcopy(root->right);
        return nroot;
    }
};
