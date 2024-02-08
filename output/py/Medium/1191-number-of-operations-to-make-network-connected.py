#https://leetcode.com/problems/number-of-operations-to-make-network-connected/
#There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
#You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
#Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
# 
#Example 1:
#Input: n = 4, connections = [[0,1],[0,2],[1,2]]
#Output: 1
#Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
#Example 2:
#Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
#Output: 2
#Example 3:
#Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
#Output: -1
#Explanation: There are not enough cables.
# 
#Constraints:
#	1 <= n <= 105
#	1 <= connections.length <= min(n * (n - 1) / 2, 105)
#	connections[i].length == 2
#	0 <= ai, bi < n
#	ai != bi
#	There are no repeated connections.
#	No two computers are connected by more than one cable.
class Solution(object):
    def makeConnected(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        #Approach 1: Union Find
		#Time Complexity: O(N + E)
		#Space Complexity: O(N)
		#Runtime: 1000 ms, faster than 5.06% of Python3 online submissions for Number of Operations to Make Network Connected.
		#Memory Usage: 36.2 MB, less than 5.06% of Python3 online submissions for Number of Operations to Make Network Connected.
        # def find(x):
        #     if x != parent[x]:
        #         parent[x] = find(parent[x])
        #     return parent[x]
        # parent, ans = list(range(n)), 0
        # for u, v in connections:
        #     pu, pv = find(u), find(v)
        #     if pu == pv:
        #         ans += 1
        #     else:
        #         parent[pu] = pv
        # return ans if ans >= n - 1 else -1
		#Approach 2: DFS
		#Time Complexity: O(N + E)
		#Space Complexity: O(N)
		#Runtime: 1000 ms, faster than 5.06% of Python3 online submissions for Number of Operations to Make Network Connected.
		#Memory Usage: 36.3 MB, less than 5.06% of Python3 online submissions for Number of Operations to Make Network Connected.
        graph, visited, ans = [[] for _ in range(n)], [False] * n, 0
        for u, v in connections:
            graph[u].append(v)
            graph[v].append(u)
        def dfs(node):
            visited[node] = True
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    dfs(neighbor)
        for i in range(n):
            if not visited[i]:
                dfs(i)
                ans += 1
        return ans if ans >= n - 1 else -1