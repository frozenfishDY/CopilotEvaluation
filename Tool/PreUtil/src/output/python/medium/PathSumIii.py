#https://leetcode.com/problems/path-sum-iii/
#Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
#The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: int
        """
        if not root:
            return 0
        return self.pathSumFrom(root, targetSum) + self.pathSum(root.left, targetSum) + self.pathSum(root.right, targetSum)
        

    