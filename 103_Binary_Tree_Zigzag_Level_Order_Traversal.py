# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    # @param root, a tree node
    # @return a list of lists of integers
    def zigzagLevelOrder(self, root):
        levels = []
        if root is None:
            return levels
        queue = [(root, 0)]
        while queue:
            cur, lev = queue.pop(0)
            try:
                levels[lev].append(cur.val)
            except IndexError:
                levels.append([cur.val])

            if cur.left is not None:
                queue.append((cur.left, lev + 1))
            if cur.right is not None:
                queue.append((cur.right, lev + 1))

        for idx in range(1, len(levels), 2):
            levels[idx].reverse()

        return levels
