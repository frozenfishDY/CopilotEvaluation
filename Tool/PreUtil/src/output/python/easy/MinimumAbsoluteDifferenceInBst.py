#https://leetcode.com/problems/minimum-absolute-difference-in-bst/
#Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """       
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 0
        if root.left is None:
            return min(abs(root.val - root.right.val), self.getMinimumDifference(root.right))
        if root.right is None:
            return min(abs(root.val - root.left.val), self.getMinimumDifference(root.left))
        return min(abs(root.val - root.left.val), abs(root.val - root.right.val), self.getMinimumDifference(root.left), self.getMinimumDifference(root.right))

    