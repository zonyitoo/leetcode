#include "leetcode.hpp"

#include <queue>
using std::queue;

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
private:
    struct Node {
        TreeNode *node;
        int curnum;

        Node(TreeNode *node, int curnum = 0)
            : node(node), curnum(curnum) {}
    };
public:
    int sumNumbers(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<Node> q;
        q.push(Node(root, root->val));
        int sum = 0;
        while (!q.empty()) {
            Node cur = q.front();
            q.pop();

            if (cur.node->left == nullptr && cur.node->right == nullptr) {
                sum += cur.curnum;
            }

            if (cur.node->left != nullptr) {
                q.push(Node(cur.node->left, cur.curnum * 10 + cur.node->left->val));
            }
            if (cur.node->right != nullptr) {
                q.push(Node(cur.node->right, cur.curnum * 10 + cur.node->right->val));
            }
        }

        return sum;
    }
};
