#https://leetcode.com/problems/search-in-a-binary-search-tree/
#You are given the root of a binary search tree (BST) and an integer val.
#Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def searchBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """       
        if root==None:
            return None
        if root.val==val:
            return root
        if root.val>val:
            return self.searchBST(root.left, val)
        else:
            return self.searchBST(root.right, val)
        
        return None
        

    