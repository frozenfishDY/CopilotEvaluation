#https://leetcode.com/problems/shortest-path-visiting-all-nodes/
#You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.
#Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.


class Solution(object):
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        if len(graph)==1:
            return 0
        if len(graph)==2:
            return 1
        result=0
        for i in range(len(graph)):
            result=max(result,self.shortestPathLengthHelper(graph,i))
        return result
        
        
    