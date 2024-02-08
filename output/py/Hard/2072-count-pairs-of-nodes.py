#https://leetcode.com/problems/count-pairs-of-nodes/
#You are given an undirected graph defined by an integer n, the number of nodes, and a 2D integer array edges, the edges in the graph, where edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi. You are also given an integer array queries.
#Let incident(a, b) be defined as the number of edges that are connected to either node a or b.
#The answer to the jth query is the number of pairs of nodes (a, b) that satisfy both of the following conditions:
#a < b
#incident(a, b) > queries[j]
#Return an array answers such that answers.length == queries.length and answers[j] is the answer of the jth query.
#Note that there can be multiple edges between the same two nodes.


class Solution(object):
    def countPairs(self, n, edges, queries):
        """
        :type n: int
        :type edges: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        return 0
        
        
    