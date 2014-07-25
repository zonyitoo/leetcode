# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # @param root, a tree node
    # @return an integer

    def maxDepth(self, root):
        if root is None:
            return 0
        nodes = [(root, 1)]
        max_depth = 0
        while len(nodes) != 0:
            front, depth = nodes[0]
            nodes = nodes[1:]
            if depth > max_depth:
                max_depth = depth

            if front.left is not None:
                nodes.append((front.left, depth + 1))
            if front.right is not None:
                nodes.append((front.right, depth + 1))
        return max_depth
