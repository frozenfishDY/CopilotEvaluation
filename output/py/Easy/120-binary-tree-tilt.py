#https://leetcode.com/problems/binary-tree-tilt/
#Given the root of a binary tree, return the sum of every tree node's tilt.
#The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """      
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 0
        if root.left is None:
            return abs(root.val - root.right.val) + self.findTilt(root.right)
        if root.right is None:
            return abs(root.val - root.left.val) + self.findTilt(root.left)
        return abs(root.val - root.left.val) + abs(root.val - root.right.val) + self.findTilt(root.left) + self.findTilt(root.right)

    