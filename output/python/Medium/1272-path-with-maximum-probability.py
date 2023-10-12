#https://leetcode.com/problems/path-with-maximum-probability/
#You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
#Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
#If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.
# 
#Example 1:
#Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
#Output: 0.25000
#Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
#Example 2:
#Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
#Output: 0.30000
#Example 3:
#Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
#Output: 0.00000
#Explanation: There is no path between 0 and 2.
# 
#Constraints:
#	2 <= n <= 10^4
#	0 <= start, end < n
#	start != end
#	0 <= a, b < n
#	a != b
#	0 <= succProb.length == edges.length <= 2*10^4
#	0 <= succProb[i] <= 1
#	There is at most one edge between every two nodes.
class Solution(object):
    def maxProbability(self, n, edges, succProb, start_node, end_node):
        """
        :type n: int
        :type edges: List[List[int]]
        :type succProb: List[float]
        :type start_node: int
        :type end_node: int
        :rtype: float
        """
        graph = collections.defaultdict(list)
        for i, edge in enumerate(edges):
            graph[edge[0]].append((edge[1], succProb[i]))
            graph[edge[1]].append((edge[0], succProb[i]))
        queue = [(start_node, 1)]
        visited = set()
        while queue:
            node, prob = queue.pop(0)
            if node == end_node:
                return prob
            visited.add(node)
            for next_node, next_prob in graph[node]:
                if next_node not in visited:
                    queue.append((next_node, prob * next_prob))
        return 0