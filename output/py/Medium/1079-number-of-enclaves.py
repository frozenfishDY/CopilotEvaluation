#https://leetcode.com/problems/number-of-enclaves/
#You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
#A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
#Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


class Solution(object):
    def numEnclaves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
                return
            grid[i][j] = 0
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)
        for i in range(m):
            dfs(i, 0)
            dfs(i, n - 1)
        for j in range(n):
            dfs(0, j)
            dfs(m - 1, j)
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    res += 1
        return res
        

    