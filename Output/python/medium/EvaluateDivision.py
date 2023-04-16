#https://leetcode.com/problems/evaluate-division/
#You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
#You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
#Return the answers to all queries. If a single answer cannot be determined, return -1.0.
#Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.


class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """            
        def dfs(graph,visited,src,dest):
            if src not in graph:
                return -1.0
            if src == dest:
                return 1.0
            visited.add(src)
            for nei in graph[src]:
                if nei not in visited:
                    res = dfs(graph,visited,nei,dest)
                    if res != -1.0:
                        return res*graph[src][nei]
            return -1.0
        graph = {}
        for i in range(len(equations)):
            src,dest = equations[i]
            if src not in graph:
                graph[src] = {}
            if dest not in graph:
                graph[dest] = {}
            graph[src][dest] = values[i]
            graph[dest][src] = 1/values[i]
        res = []
        for src,dest in queries:
            res.append(dfs(graph,set(),src,dest))
        return res                    







        

        

    