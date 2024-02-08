#https://leetcode.com/problems/count-sub-islands/
#You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
#An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
#Return the number of islands in grid2 that are considered sub-islands.
# 
#Example 1:
#Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
#Output: 3
#Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
#The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
#Example 2:
#Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
#Output: 2 
#Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
#The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
# 
#Constraints:
#	m == grid1.length == grid2.length
#	n == grid1[i].length == grid2[i].length
#	1 <= m, n <= 500
#	grid1[i][j] and grid2[i][j] are either 0 or 1.
class Solution(object):
    def countSubIslands(self, grid1, grid2):
        """
        :type grid1: List[List[int]]
        :type grid2: List[List[int]]
        :rtype: int
        """
        m, n = len(grid1), len(grid1[0])
        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or grid2[i][j] == 0:
                return True
            grid2[i][j] = 0
            res = grid1[i][j] == 1
            res &= dfs(i - 1, j)
            res &= dfs(i + 1, j)
            res &= dfs(i, j - 1)
            res &= dfs(i, j + 1)
            return res
        res = 0
        for i in range(m):
            for j in range(n):
                if grid2[i][j] == 1 and dfs(i, j):
                    res += 1
        return res