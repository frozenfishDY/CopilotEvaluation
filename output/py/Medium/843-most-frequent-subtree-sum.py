#https://leetcode.com/problems/most-frequent-subtree-sum/
#Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
#The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
# 
#Example 1:
#Input: root = [5,2,-3]
#Output: [2,-3,4]
#Example 2:
#Input: root = [5,2,-5]
#Output: [2]
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
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def dfs(node):
            if node is None:
                return 0

            left = dfs(node.left)
            right = dfs(node.right)
            total = node.val + left + right
            count[total] += 1
            return total

        count = collections.Counter()
        dfs(root)
        maxCount = max(count.values())
        return [total for total in count if count[total] == maxCount]
