# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # @param p, a tree node
    # @param q, a tree node
    # @return a boolean

    def isSameTree(self, p, q):
        if self.isSameNode(p, q):
            if p is not None and q is not None:
                return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
            return True
        return False

    def isSameNode(self, a, b):
        if a is not None and b is not None:
            return a.val == b.val
        else:
            return a is None and b is None
