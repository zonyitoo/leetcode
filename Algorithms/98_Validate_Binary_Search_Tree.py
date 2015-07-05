# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:

    # @param root, a tree node
    # @return a boolean
    def isValidBST(self, root):
        _, _, isvalid = self.subtreeMaxmin(root)
        return isvalid

    def subtreeMaxmin(self, root):
        if root is None:
            return None, None, True

        leftmin, leftmax, leftvalid = self.subtreeMaxmin(root.left)
        rightmin, rightmax, rightvalid = self.subtreeMaxmin(root.right)
        if not leftvalid or not rightvalid:
            return None, None, False

        mini = root.val
        if leftmin is not None:
            mini = min(mini, leftmin)
        if rightmin is not None:
            if rightmin <= root.val:
                return None, None, False
            mini = min(mini, rightmin)
        maxi = root.val
        if leftmax is not None:
            if leftmax >= root.val:
                return None, None, False
            maxi = max(maxi, leftmax)
        if rightmax is not None:
            maxi = max(maxi, rightmax)
        return mini, maxi, True
