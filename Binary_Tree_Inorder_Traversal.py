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
        nodes = [(root, False, False)]
        while len(nodes) != 0:
            last, has_left, has_right = nodes.pop()
            if not has_left:
                nodes.append((last, True, False))
                if last.left is not None:
                    nodes.append((last.left, False, False))
            elif not has_right:
                nodes.append((last, True, True))
                result.append(last.val)
                if last.right is not None:
                    nodes.append((last.right, False, False))

        return result
