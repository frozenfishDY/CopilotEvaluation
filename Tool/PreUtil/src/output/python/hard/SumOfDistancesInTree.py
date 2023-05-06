#https://leetcode.com/problems/sum-of-distances-in-tree/
#There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
#You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
#Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.


class Solution(object):
    def sumOfDistancesInTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        if n==1:
            return [0]
        if n==2:
            return [1,1]
        result=[0]*n
        for i in range(n):
            result[i]=self.sumOfDistancesInTreeHelper(n,edges,i)
        return result
        
        
    