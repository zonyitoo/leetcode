# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    # @param root, a tree node
    # @param sum, an integer
    # @return a boolean
    def hasPathSum(self, root, sum):
        if root is None:
            return False
        queue = [(root, root.val)]
        while len(queue) != 0:
            node, val = queue.pop(0)
            if val == sum and node.left is None and node.right is None:
                return True
            if node.left is not None:
                queue.append((node.left, node.left.val + val))
            if node.right is not None:
                queue.append((node.right, node.right.val + val))
        return False
