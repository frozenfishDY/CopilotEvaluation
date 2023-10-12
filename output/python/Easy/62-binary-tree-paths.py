#https://leetcode.com/problems/binary-tree-paths/
#Given the root of a binary tree, return all root-to-leaf paths in any order.
#A leaf is a node with no children.
# 
#Example 1:
#Input: root = [1,2,3,null,5]
#Output: ["1->2->5","1->3"]
#Example 2:
#Input: root = [1]
#Output: ["1"]
# 
#Constraints:
#	The number of nodes in the tree is in the range [1, 100].
#	-100 <= Node.val <= 100
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """ 
        if not root:
            return []
        if not root.left and not root.right:
            return [str(root.val)]
        left = self.binaryTreePaths(root.left)
        right = self.binaryTreePaths(root.right)
        return [str(root.val) + '->' + i for i in left + right]
