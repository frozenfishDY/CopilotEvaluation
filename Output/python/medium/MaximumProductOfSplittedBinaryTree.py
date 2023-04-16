#https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
#Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
#Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
#Note that you need to maximize the answer before taking the mod and not after taking it.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxProduct(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        if not root.left and not root.right:
            return root.val
        if not root.left:
            return self.maxProduct(root.right)
        if not root.right:
            return self.maxProduct(root.left)
        return self.maxProduct(root.left) + self.maxProduct(root.right)
        

    