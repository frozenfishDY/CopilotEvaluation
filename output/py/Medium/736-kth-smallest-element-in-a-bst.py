#https://leetcode.com/problems/kth-smallest-element-in-a-bst/
#Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.k = k
        self.res = None
        def dfs(root):
            if not root:
                return
            dfs(root.left)
            self.k -= 1
            if self.k == 0:
                self.res = root.val
                return
            dfs(root.right)
        dfs(root)
        return self.res
        

    