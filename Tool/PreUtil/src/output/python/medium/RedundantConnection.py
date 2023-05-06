#https://leetcode.com/problems/redundant-connection/
#In this problem, a tree is an undirected graph that is connected and has no cycles.
#You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
#Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.


class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        res = 0
        for i in range(len(edges)):
            for j in range(i+1,len(edges)):
                if edges[i] == edges[j]:
                    res += 1
        return res
        

    