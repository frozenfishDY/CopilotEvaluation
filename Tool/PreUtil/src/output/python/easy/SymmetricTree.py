#https://leetcode.com/problems/symmetric-tree/
#Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root==None:
            return True
        else:
            return self.isMirror(root.left,root.right)

    