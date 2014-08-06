#include <queue>
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
        if (root == NULL) {
            return 0;
        }
        queue<Node> q;
        q.push(Node(root, root->val));
        int sum = 0;
        while (!q.empty()) {
            Node cur = q.front();
            q.pop();

            if (cur.node->left == NULL && cur.node->right == NULL) {
                sum += cur.curnum;
            }

            if (cur.node->left != NULL) {
                q.push(Node(cur.node->left, cur.curnum * 10 + cur.node->right->val));
            }
            if (cur.node->right != NULL) {
                q.push(Node(cur.node->right, cur.curnum * 10 + cur.node->right->val));
            }
        }

        return sum;
    }
};
