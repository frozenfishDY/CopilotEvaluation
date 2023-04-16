#https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
#Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """       
        if root is None:
            return False
        if root.left is None and root.right is None:
            return False
        if root.left is None:
            return self.findTarget(root.right, k)
        if root.right is None:
            return self.findTarget(root.left, k)
        if self.findTarget(root.left, k) or self.findTarget(root.right, k):
            return True
        else:
            return self.findTarget(root.left, k-root.val) or self.findTarget(root.right, k-root.val)
        
        return False
        

    