#https://leetcode.com/problems/balanced-binary-tree/
#Given a binary tree, determine if it is height-balanced.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root==None:
            return True
        else:
            return abs(self.height(root.left)-self.height(root.right))<=1 and self.isBalanced(root.left) and self.isBalanced(root.right)

    