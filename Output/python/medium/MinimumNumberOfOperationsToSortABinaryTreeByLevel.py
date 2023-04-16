#https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
#You are given the root of a binary tree with unique values.
#In one operation, you can choose any two nodes at the same level and swap their values.
#Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
#The level of a node is the number of edges along the path between it and the root node.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minimumOperations(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        # 1. Get the levels of the tree
        # 2. Get the minimum number of operations to sort each level
        # 3. Return the sum of the minimum number of operations to sort each level
        levels = self.get_levels(root)
        operations = 0
        for level in levels:
            operations += self.get_operations(level)
        return operations
        

    