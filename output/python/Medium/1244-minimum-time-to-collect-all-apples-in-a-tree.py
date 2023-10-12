#https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
#Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.
#The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.
# 
#Example 1:
#Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
#Output: 8 
#Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
#Example 2:
#Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
#Output: 6
#Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
#Example 3:
#Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
#Output: 0
# 
#Constraints:
#	1 <= n <= 105
#	edges.length == n - 1
#	edges[i].length == 2
#	0 <= ai < bi <= n - 1
#	hasApple.length == n
class Solution(object):
    def minTime(self, n, edges, hasApple):
        """
        :type n: int
        :type edges: List[List[int]]
        :type hasApple: List[bool]
        :rtype: int
        """
        # 1. construct the tree
        # 2. find the path from 0 to each node
        # 3. add the path length if the node has apple
        # 4. return the sum of path length
        # 5. the time complexity is O(n)
        # 6. the space complexity is O(n)
        tree = [[] for _ in range(n)]
        for edge in edges:
            tree[edge[0]].append(edge[1])
            tree[edge[1]].append(edge[0])

        def dfs(node, parent):
            res = 0
            for child in tree[node]:
                if child != parent:
                    res += dfs(child, node)
            if res > 0 or hasApple[node]:
                return res + 2
            return 0

        return max(0, dfs(0, -1) - 2)