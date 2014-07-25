# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # @param root, a tree node
    # @return a list of integers

    def preorderTraversal(self, root):
        if root is None:
            return []
        result = [root.val]
        result += self.preorderTraversal(root.left)
        result += self.preorderTraversal(root.right)
        return result
