#https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
#Given the root of a binary tree and an integer limit, delete all insufficient nodes in the tree simultaneously, and return the root of the resulting binary tree.
#A node is insufficient if every root to leaf path intersecting this node has a sum strictly less than limit.
#A leaf is a node with no children.
# 
#Example 1:
#Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
#Output: [1,2,3,4,null,null,7,8,9,null,14]
#Example 2:
#Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
#Output: [5,4,8,11,null,17,4,7,null,null,null,5]
#Example 3:
#Input: root = [1,2,-3,-5,null,4,null], limit = -1
#Output: [1,null,-3,4]
# 
#Constraints:
#	The number of nodes in the tree is in the range [1, 5000].
#	-105 <= Node.val <= 105
#	-109 <= limit <= 109
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sufficientSubset(self, root, limit):
        """
        :type root: TreeNode
        :type limit: int
        :rtype: TreeNode
        """
        #Solution
        #1. Initialize the result to 0
        #2. For each number in root, check if it is 1
        #3. If it is, check if the number is surrounded by 0's
        #4. If it is, increase the result by 1
        #5. Return the result
        #
        #Example:
        #root: [1,2,3], limit = 5
        #ret: 2
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        
        ret = 0
        for num in root:
            for i in range(len(ret)):
                if num == 1:
                    ret[i] = 1

        return ret