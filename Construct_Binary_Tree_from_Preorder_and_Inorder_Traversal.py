from leetcode import TreeNode
# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    # @param preorder, a list of integers
    # @param inorder, a list of integers
    # @return a tree node
    def buildTree(self, preorder, inorder):
        return self.__buildTree(iter(preorder), inorder)

    def __buildTree(self, preorder_itr, inorder):
        if not inorder:
            return None
        try:
            curpre = next(preorder_itr)
        except StopIteration:
            return None

        idx = inorder.index(curpre)
        root = TreeNode(curpre)
        root.left = self.__buildTree(preorder_itr, inorder[:idx])
        root.right = self.__buildTree(preorder_itr, inorder[idx + 1:])
        return root
