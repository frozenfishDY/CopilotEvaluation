#https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/
#You are given the root of a binary search tree and an array queries of size n consisting of positive integers.
#Find a 2D array answer of size n where answer[i] = [mini, maxi]:
#mini is the largest value in the tree that is smaller than or equal to queries[i]. If a such value does not exist, add -1 instead.
#maxi is the smallest value in the tree that is greater than or equal to queries[i]. If a such value does not exist, add -1 instead.
#Return the array answer.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def closestNodes(self, root, queries):
        """
        :type root: Optional[TreeNode]
        :type queries: List[int]
        :rtype: List[List[int]]
        """
        # 1. Loop through the queries
        # 2. For each query, get the closest nodes
        # 3. Add the closest nodes to the result
        # 4. Return the result
        result = []
        for query in queries:
            closest_nodes = self.get_closest_nodes(root, query)
            result.append(closest_nodes)
        return result
        

    