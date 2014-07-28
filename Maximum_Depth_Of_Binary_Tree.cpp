#include <queue>
using std::queue;
using std::pair;
using std::make_pair;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
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
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
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

            if (cur.first->left != NULL) {
                q.push(make_pair(cur.first->left, cur.second + 1));
            }
            if (cur.first->right != NULL) {
                q.push(make_pair(cur.first->right, cur.second + 1));
            }
        }
        return max_depth;
    }
};
