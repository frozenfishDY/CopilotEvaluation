#https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
#Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.
#Note:
#The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
#A subtree of root is a tree consisting of root and all of its descendants.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def averageOfSubtree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        if root==None:
            return 0
        if root.left==None and root.right==None:
            return 1
        return self.averageOfSubtree(root.left)+self.averageOfSubtree(root.right)+1
        
    