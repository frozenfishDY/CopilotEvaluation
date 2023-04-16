#https://leetcode.com/problems/diameter-of-binary-tree/
#Given the root of a binary tree, return the length of the diameter of the tree.
#The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
#The length of a path between two nodes is represented by the number of edges between them.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """      
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 0
        if root.left is None:
            return max(self.height(root.right), self.diameterOfBinaryTree(root.right))
        if root.right is None:
            return max(self.height(root.left), self.diameterOfBinaryTree(root.left))
        return max(self.height(root.left) + self.height(root.right), self.diameterOfBinaryTree(root.left), self.diameterOfBinaryTree(root.right))      
        