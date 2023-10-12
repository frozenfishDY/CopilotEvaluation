#https://leetcode.com/problems/find-duplicate-subtrees/
#Given the root of a binary tree, return all duplicate subtrees.
#For each kind of duplicate subtrees, you only need to return the root node of any one of them.
#Two trees are duplicate if they have the same structure with the same node values.
# 
#Example 1:
#Input: root = [1,2,3,4,null,2,4,null,null,4]
#Output: [[2,4],[4]]
#Example 2:
#Input: root = [2,1,1]
#Output: [[1]]
#Example 3:
#Input: root = [2,2,2,3,null,3,null]
#Output: [[2,3],[3]]
# 
#Constraints:
#	The number of the nodes in the tree will be in the range [1, 5000]
#	-200 <= Node.val <= 200
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        #Solution
        #1. For each node in the tree, get the preorder traversal of the node
        #2. Add the preorder traversal of the node to the result
        #3. Return the result
        #
        #Example:
        #root: [1,2,3,4,null,2,4,null,null,4]
        #ret: [[2,4],[4]]
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        def preorder(root):
            if root is None:
                return "#"
            left = preorder(root.left)
            right = preorder(root.right)
            subtree = str(root.val) + "," + left + "," + right
            if subtree in subtrees:
                if subtree not in ret:
                    ret.append(subtree)
            else:
                subtrees.add(subtree)
            return subtree

        ret = []
        subtrees = set()
        preorder(root)
        return ret