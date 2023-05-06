#https://leetcode.com/problems/deepest-leaves-sum/
#Given the root of a binary tree, return the sum of values of its deepest leaves.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def deepestLeavesSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        if not root.left and not root.right:
            return root.val
        if not root.left:
            return self.deepestLeavesSum(root.right)
        if not root.right:
            return self.deepestLeavesSum(root.left)
        return self.deepestLeavesSum(root.left) + self.deepestLeavesSum(root.right)
        

    