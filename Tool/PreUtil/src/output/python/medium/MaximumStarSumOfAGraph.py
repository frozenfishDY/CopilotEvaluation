#https://leetcode.com/problems/maximum-star-sum-of-a-graph/
#There is an undirected graph consisting of n nodes numbered from 0 to n - 1. You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node.
#You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
#A star graph is a subgraph of the given graph having a center node containing 0 or more neighbors. In other words, it is a subset of edges of the given graph such that there exists a common node for all edges.
#The image below shows star graphs with 3 and 4 neighbors respectively, centered at the blue node.


class Solution(object):
    def maxStarSum(self, vals, edges, k):
        """
        :type vals: List[int]
        :type edges: List[List[int]]
        :type k: int
        :rtype: int
        """                        
        n = len(vals)
        graph = [[] for _ in range(n)]
        for u,v in edges:
            graph[u].append(v)
            graph[v].append(u)
        res = 0
        for i in range(n):
            res = max(res,vals[i]+self.dfs(graph,i,k,vals))
        return res



           

        

    