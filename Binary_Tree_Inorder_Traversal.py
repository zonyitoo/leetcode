# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # @param root, a tree node
    # @return a list of integers

    def inorderTraversal(self, root):
        if root is None:
            return []
        result = []
        nodes = [(root, 0)]
        while len(nodes) != 0:
            last, state = nodes.pop()
            if state == 0:
                nodes.append((last, 1))
                if last.left is not None:
                    nodes.append((last.left, 0))
            elif state == 1:
                nodes.append((last, 2))
                result.append(last.val)
                if last.right is not None:
                    nodes.append((last.right, 0))

        return result
