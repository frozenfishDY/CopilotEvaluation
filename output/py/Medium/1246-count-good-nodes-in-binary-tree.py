#https://leetcode.com/problems/count-good-nodes-in-binary-tree/
#Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
#Return the number of good nodes in the binary tree.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # 1. Get the number of good nodes in the tree
        # 2. Return the number of good nodes in the tree
        return self.get_good_nodes(root, root.val)
        

    