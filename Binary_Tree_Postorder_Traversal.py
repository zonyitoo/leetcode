# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    # @param root, a tree node
    # @return a list of integers
    def postorderTraversal(self, root):
        result = []
        if root is None:
            return result
        nodes = [(root, 0)]
        while len(nodes) != 0:
            node, state = nodes.pop()
            if state == 0:
                nodes.append((node, 1))
                if node.left is not None:
                    nodes.append((node.left, 0))
            elif state == 1:
                nodes.append((node, 2))
                if node.right is not None:
                    nodes.append((node.right, 0))
            else:
                result.append(node.val)
        return result
