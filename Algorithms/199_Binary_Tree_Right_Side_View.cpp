#include "leetcode.hpp"

#include <vector>
#include <queue>
#include <tuple>
using std::vector;
using std::queue;
using std::tuple;

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
    vector<int> rightSideView(const TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;

        queue<tuple<const TreeNode*, int>> q;
        q.push(std::make_tuple(root, 0));

        tuple<const TreeNode*, int> prev = std::make_tuple(nullptr, -1);
        int last_level = -1;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            const TreeNode* curnode;
            int level;
            std::tie(curnode, level) = cur;

            if (level != std::get<1>(prev) && std::get<1>(prev) != -1) {
                res.push_back(std::get<0>(prev)->val);
                last_level = std::get<1>(prev);
            }

            prev = cur;

            if (curnode->left != nullptr) {
                q.push(std::make_tuple(curnode->left, level + 1));
            }

            if (curnode->right != nullptr) {
                q.push(std::make_tuple(curnode->right, level + 1));
            }
        }

        if (last_level != std::get<1>(prev)) {
            res.push_back(std::get<0>(prev)->val);
        }

        return std::move(res);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->right = new TreeNode(5);
    // root->right->right = new TreeNode(4);

    auto ret = Solution().rightSideView(root);

    for (int i = 0; i < ret.size(); ++i) {
        printf("%d ", ret[i]);
    }
    printf("\n");
    return 0;
}
