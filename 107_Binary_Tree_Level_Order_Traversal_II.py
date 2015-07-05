# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrderBottom(self, root):
        level = []
        if root is None:
            return level
        queue = [(root, 0)]
        while len(queue) != 0:
            node, l = queue.pop(0)
            if l == len(level):
                level.append([])
            level[l].append(node.val)
            if node.left is not None:
                queue.append((node.left, l + 1))
            if node.right is not None:
                queue.append((node.right, l + 1))
        level.reverse()
        return level
