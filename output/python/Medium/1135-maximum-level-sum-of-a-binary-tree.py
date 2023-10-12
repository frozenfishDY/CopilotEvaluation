#https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
#Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
#Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
# 
#Example 1:
#Input: root = [1,7,0,7,-8,null,null]
#Output: 2
#Explanation: 
#Level 1 sum = 1.
#Level 2 sum = 7 + 0 = 7.
#Level 3 sum = 7 + -8 = -1.
#So we return the level with the maximum sum which is level 2.
#Example 2:
#Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
#Output: 2
# 
#Constraints:
#	The number of nodes in the tree is in the range [1, 104].
#	-105 <= Node.val <= 105
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxLevelSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # Approach 1: BFS
        # Time Complexity: O(N)
        # Space Complexity: O(N)
        # Runtime: 280 ms, faster than 99.01% of Python online submissions for Maximum Level Sum of a Binary Tree.
        # Memory Usage: 21.9 MB, less than 100.00% of Python online submissions for Maximum Level Sum of a Binary Tree.
        level, max_sum, max_level, q = 0, float('-inf'), 0, [root]
        while q:
            level += 1
            level_sum = sum([node.val for node in q])
            if level_sum > max_sum:
                max_sum, max_level = level_sum, level
            q = [child for node in q for child in [node.left, node.right] if child]
        return max_level