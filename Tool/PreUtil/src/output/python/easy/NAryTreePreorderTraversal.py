#https://leetcode.com/problems/n-ary-tree-preorder-traversal/
#Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
#Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)


"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """ 
        if root==None:
            return []
        if root.children==None:
            return [root.val]
        res=[root.val]
        for child in root.children:
            res.extend(self.preorder(child))
        return res
        

    