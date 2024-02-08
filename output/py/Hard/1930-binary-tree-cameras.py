#https://leetcode.com/problems/binary-tree-cameras/
#You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
#Return the minimum number of cameras needed to monitor all nodes of the tree.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minCameraCover(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        if not root.left and not root.right:
            return 1
        if not root.left:
            return self.minCameraCover(root.right)+1
        if not root.right:
            return self.minCameraCover(root.left)+1
        return min(self.minCameraCover(root.left),self.minCameraCover(root.right))+1
        
        
    