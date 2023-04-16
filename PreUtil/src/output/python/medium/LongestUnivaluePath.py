#https://leetcode.com/problems/longest-univalue-path/
#Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.
#The length of the path between two nodes is represented by the number of edges between them.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 0
        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            left = left + 1 if root.left and root.left.val == root.val else 0
            right = right + 1 if root.right and root.right.val == root.val else 0
            self.res = max(self.res,left+right)
            return max(left,right)
        dfs(root)
        return self.res
        

    