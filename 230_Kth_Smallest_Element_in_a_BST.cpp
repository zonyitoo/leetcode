#include "leetcode.hpp"

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
    int kthSmallest(const TreeNode* const root, int k) {
        int ans = 0;
        this->solve(root, k, ans);

        return ans;
    }

  private:
    void solve(const TreeNode* const root, int &k, int& ans) {
        if (root == nullptr) {
            return;
        }

        this->solve(root->left, k, ans);

        k -= 1;

        if (k == 0) {
            ans = root->val;
            return;
        } else if (k < 0) {
            // Already found
            return;
        }

        this->solve(root->right, k, ans);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    int ret = Solution().kthSmallest(root, 3);

    printf("%d\n", ret);

    return 0;
}
