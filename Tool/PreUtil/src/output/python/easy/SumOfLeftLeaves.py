#https://leetcode.com/problems/sum-of-left-leaves/
#Given the root of a binary tree, return the sum of all left leaves.
#A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """ 
        if root==None:
            return 0
        if root.left==None and root.right==None:
            return 0
        if root.left!=None and root.left.left==None and root.left.right==None:
            return root.left.val+self.sumOfLeftLeaves(root.right)
        return self.sumOfLeftLeaves(root.left)+self.sumOfLeftLeaves(root.right)

    