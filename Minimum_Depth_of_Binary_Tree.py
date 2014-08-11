# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    # @param root, a tree node
    # @return an integer
    def minDepth(self, root):
        if root is None:
            return 0
        self.min_depth = (1 << 32) - 1
        self.dfs(root)
        return self.min_depth

    def dfs(self, root, curdepth=1):
        if curdepth >= self.min_depth:
            return

        if root.left is None and root.right is None:
            if curdepth < self.min_depth:
                self.min_depth = curdepth
            return

        if root.left is not None:
            self.dfs(root.left, curdepth + 1)
        if root.right is not None:
            self.dfs(root.right, curdepth + 1)
