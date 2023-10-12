#https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
#There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.
#A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.
#The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.
#Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.
# 
#Example 1:
#Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
#Output: 3
#Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
#1) 1 --> 2 --> 5
#2) 1 --> 2 --> 3 --> 5
#3) 1 --> 3 --> 5
#Example 2:
#Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
#Output: 1
#Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.
# 
#Constraints:
#	1 <= n <= 2 * 104
#	n - 1 <= edges.length <= 4 * 104
#	edges[i].length == 3
#	1 <= ui, vi <= n
#	ui != vi
#	1 <= weighti <= 105
#	There is at most one edge between any two nodes.
#	There is at least one path between any two nodes.
class Solution(object):
    def countRestrictedPaths(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """   
        g = collections.defaultdict(list)
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w))
        d = [float('inf')] * (n + 1)
        d[n] = 0
        q = collections.deque([n])
        while q:
            u = q.popleft()
            for v, w in g[u]:
                if d[v] > d[u] + w:
                    d[v] = d[u] + w
                    q.append(v)
        dp = [0] * (n + 1)
        dp[n] = 1
        for _, u, v in sorted((d[i], i, j) for i in range(1, n + 1) for j, _ in g[i]):
            dp[u] = (dp[u] + dp[v]) % (10**9 + 7)
        return dp[1]