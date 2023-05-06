#https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
#Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
#For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
#The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
#Return the vertical order traversal of the binary tree.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def verticalTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """       
        if not root:
            return []
        if not root.left and not root.right:
            return [[root.val]]
        if not root.left:
            return [[root.val]]+self.verticalTraversal(root.right)
        if not root.right:
            return self.verticalTraversal(root.left)+[[root.val]]
        return self.verticalTraversal(root.left)+[[root.val]]+self.verticalTraversal(root.right)

        
        
    