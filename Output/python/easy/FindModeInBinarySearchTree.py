#https://leetcode.com/problems/find-mode-in-binary-search-tree/
#Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
#If the tree has more than one mode, return them in any order.
#Assume a BST is defined as follows:
#The left subtree of a node contains only nodes with keys less than or equal to the node's key.
#The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
#Both the left and right subtrees must also be binary search trees.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """        
        if root is None:
            return []
        if root.left is None and root.right is None:
            return [root.val]
        if root.left is None:
            return [root.val] + self.findMode(root.right)
        if root.right is None:
            return [root.val] + self.findMode(root.left)
        return [root.val] + self.findMode(root.left) + self.findMode(root.right)  
         

    