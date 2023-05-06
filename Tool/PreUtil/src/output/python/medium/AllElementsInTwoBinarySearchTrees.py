#https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
#Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getAllElements(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: List[int]
        """
        if not root1 and not root2:
            return []
        if not root1:
            return self.inorder(root2)
        if not root2:
            return self.inorder(root1)
        return sorted(self.inorder(root1) + self.inorder(root2))
        

    