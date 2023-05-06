#https://leetcode.com/problems/smallest-string-starting-from-leaf/
#You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.
#Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
#As a reminder, any shorter prefix of a string is lexicographically smaller.
#For example, "ab" is lexicographically smaller than "aba".
#A leaf of a node is a node that has no children.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def smallestFromLeaf(self, root):
        """
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""
        if not root.left and not root.right:
            return chr(root.val + ord('a'))
        left = self.smallestFromLeaf(root.left)
        right = self.smallestFromLeaf(root.right)
        if root.left and root.right:
            return min(left + chr(root.val + ord('a')), right + chr(root.val + ord('a')))
        elif root.left:
            return left + chr(root.val + ord('a'))
        else:
            return right + chr(root.val + ord('a'))
        

    