#https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
#Given the root of a binary tree, flatten the tree into a "linked list":
#The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
#The "linked list" should be in the same order as a pre-order traversal of the binary tree.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        if not root:
            return None
        self.flatten(root.left)
        self.flatten(root.right)
        if root.left:
            temp = root.right
            root.right = root.left
            root.left = None
            while root.right:
                root = root.right
            root.right = temp
        return root
        

    