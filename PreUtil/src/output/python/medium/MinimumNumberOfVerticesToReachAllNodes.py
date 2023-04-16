#https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
#Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
#Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.
#Notice that you can return the vertices in any order.


class Solution(object):
    def findSmallestSetOfVertices(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        in_degree=[0]*n
        for edge in edges:
            in_degree[edge[1]]+=1
        return [i for i in range(n) if in_degree[i]==0]
        

    