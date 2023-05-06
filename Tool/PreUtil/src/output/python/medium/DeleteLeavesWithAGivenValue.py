#https://leetcode.com/problems/delete-leaves-with-a-given-value/
#Given a binary tree root and an integer target, delete all the leaf nodes with value target.
#Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def removeLeafNodes(self, root, target):
        """
        :type root: TreeNode
        :type target: int
        :rtype: TreeNode
        """
        if not root:
            return None
        if not root.left and not root.right:
            if root.val == target:
                return None
            else:
                return root
        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)
        if not root.left and not root.right:
            if root.val == target:
                return None
            else:
                return root
        return root
        

    