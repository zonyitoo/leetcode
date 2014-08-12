from leetcode import TreeNode, tree_to_str

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    # @param inorder, a list of integers
    # @param postorder, a list of integers
    # @return a tree node
    def buildTree(self, inorder, postorder):
        return self.__buildTree(inorder, postorder, iter(range(len(postorder) - 1, -1, -1)))

    def __buildTree(self, inorder, postorder, idx_itr):
        if not inorder:
            return None
        pidx = next(idx_itr)
        root = TreeNode(postorder[pidx])
        idx = inorder.index(postorder[pidx])
        root.right = self.__buildTree(inorder[idx + 1:], postorder, idx_itr)
        root.left = self.__buildTree(inorder[:idx], postorder, idx_itr)
        return root


if __name__ == '__main__':
    s = Solution()
    print(tree_to_str(s.buildTree([1, 2, 3, 4, 5], [1, 3, 5, 4, 2])))
    print(tree_to_str(s.buildTree([1, 2, 3, 4], [3, 2, 4, 1])))
