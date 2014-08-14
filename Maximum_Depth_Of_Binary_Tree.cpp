#include "leetcode.hpp"

#include <queue>
using std::queue;
using std::pair;
using std::make_pair;

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
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root, 1));
        int max_depth = 0;
        while (!q.empty()) {
            pair<TreeNode *, int> cur = q.front();
            q.pop();
            if (cur.second > max_depth) {
                max_depth = cur.second;
            }

            if (cur.first->left != nullptr) {
                q.push(make_pair(cur.first->left, cur.second + 1));
            }
            if (cur.first->right != nullptr) {
                q.push(make_pair(cur.first->right, cur.second + 1));
            }
        }
        return max_depth;
    }
};
