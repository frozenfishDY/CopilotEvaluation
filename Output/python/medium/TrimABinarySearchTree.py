#https://leetcode.com/problems/trim-a-binary-search-tree/
#Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.
#Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def trimBST(self, root, low, high):
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: TreeNode
        """
        if root:
            if root.val < low:
                return self.trimBST(root.right, low, high)
            elif root.val > high:
                return self.trimBST(root.left, low, high)
            else:
                root.left = self.trimBST(root.left, low, high)
                root.right = self.trimBST(root.right, low, high)
                return root
        return None
        

    