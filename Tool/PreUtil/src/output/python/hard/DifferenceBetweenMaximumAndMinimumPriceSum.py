#https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/
#There exists an undirected and initially unrooted tree with n nodes indexed from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
#Each node has an associated price. You are given an integer array price, where price[i] is the price of the ith node.
#The price sum of a given path is the sum of the prices of all nodes lying on that path.
#The tree can be rooted at any node root of your choice. The incurred cost after choosing root is the difference between the maximum and minimum price sum amongst all paths starting at root.
#Return the maximum possible cost amongst all possible root choices.


class Solution(object):
    def maxOutput(self, n, edges, price):
        """
        :type n: int
        :type edges: List[List[int]]
        :type price: List[int]
        :rtype: int
        """
        if n==1:
            return 0
        if n==2:
            return abs(price[0]-price[1])
        result=0
        for i in range(n):
            result=max(result,self.maxOutputHelper(n,edges,price,i))
        return result
        
        
    