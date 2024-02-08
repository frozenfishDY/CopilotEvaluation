#https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
#Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.
#Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
#If no such second minimum value exists, output -1 instead.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """ 
        if root==None:
            return -1
        if root.left==None and root.right==None:
            return -1
        if root.left.val==root.val:
            left=self.findSecondMinimumValue(root.left)
        else:
            left=root.left.val
        if root.right.val==root.val:
            right=self.findSecondMinimumValue(root.right)
        else:
            right=root.right.val
        if left==-1:
            return right
        if right==-1:
            return left
        return min(left,right)
        
        

    