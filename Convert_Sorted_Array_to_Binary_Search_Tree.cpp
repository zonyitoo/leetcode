#include <vector>
using std::vector;

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
    TreeNode *sortedArrayToBST(const vector<int> &num) {
        if (num.empty()) {
            return nullptr;
        }
        TreeNode *head = nullptr;
        arrayToBST(&head, num.begin(), num.end());

        return head;
    }

    void arrayToBST(TreeNode **node, vector<int>::const_iterator begin, vector<int>::const_iterator end) {
        auto mid = begin + (end - begin) / 2;
        *node = new TreeNode(*mid);
        if (begin != mid) {
            arrayToBST(&(*node)->left, begin, mid);
        }
        if (mid + 1 != end) {
            arrayToBST(&(*node)->right, mid + 1, end);
        }
    }
};
