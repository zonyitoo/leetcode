# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    # @param root, a tree node
    # @return nothing, do it in place
    def flatten(self, root):
        if root is None:
            return
        stack = [(root, root.left, root.right, 0)]
        cur = root
        while stack:
            node, left, right, state = stack.pop()
            if state == 0:
                stack.append((node, left, right, 1))
                if left is not None:
                    cur.right = left
                    cur.left = None
                    cur = cur.right
                    stack.append((left, left.left, left.right, 0))
            elif state == 1:
                stack.append((node, left, right, 2))
                if right is not None:
                    cur.right = right
                    cur.left = None
                    cur = cur.right
                    stack.append((right, right.left, right.right, 0))
