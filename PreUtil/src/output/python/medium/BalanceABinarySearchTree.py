#https://leetcode.com/problems/balance-a-binary-search-tree/
#Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
#A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def balanceBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """       
        # 1. Get the list of all the nodes in the tree
        # 2. Sort the list
        # 3. Create a new tree with the sorted list
        # 4. Return the new tree
        node_list = []
        self.get_nodes(root, node_list)
        node_list.sort()
        new_tree = self.create_tree(node_list)
        return new_tree

        

    