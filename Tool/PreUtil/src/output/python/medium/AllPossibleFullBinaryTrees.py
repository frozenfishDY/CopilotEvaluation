#https://leetcode.com/problems/all-possible-full-binary-trees/
#Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.
#Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.
#A full binary tree is a binary tree where each node has exactly 0 or 2 children.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def allPossibleFBT(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n % 2 == 0:
            return []
        if n == 1:
            return [TreeNode(0)]
        res = []
        for i in range(1, n, 2):
            left = self.allPossibleFBT(i)
            right = self.allPossibleFBT(n - i - 1)
            for l in left:
                for r in right:
                    root = TreeNode(0)
                    root.left = l
                    root.right = r
                    res.append(root)
        return res
        

    