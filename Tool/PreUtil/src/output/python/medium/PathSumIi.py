#https://leetcode.com/problems/path-sum-ii/
#Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
#A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.


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
        :rtype: List[List[int]]
        """
        if not root:
            return []
        if not root.left and not root.right:
            if root.val == targetSum:
                return [[root.val]]
            else:
                return []
        left = self.pathSum(root.left, targetSum - root.val)
        right = self.pathSum(root.right, targetSum - root.val)
        return [[root.val] + i for i in left + right]
        

    