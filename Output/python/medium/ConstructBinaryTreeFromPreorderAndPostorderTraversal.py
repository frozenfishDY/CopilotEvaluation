#https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
#Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
#If there exist multiple answers, you can return any of them.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def constructFromPrePost(self, preorder, postorder):
        """
        :type preorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if not preorder:
            return None
        root = TreeNode(preorder[0])
        if len(preorder) == 1:
            return root
        index = postorder.index(preorder[1])
        root.left = self.constructFromPrePost(preorder[1:index+2], postorder[:index+1])
        root.right = self.constructFromPrePost(preorder[index+2:], postorder[index+1:-1])
        return root
        

    