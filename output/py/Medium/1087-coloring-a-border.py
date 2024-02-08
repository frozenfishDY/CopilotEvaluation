#https://leetcode.com/problems/coloring-a-border/
#You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.
#Two squares belong to the same connected component if they have the same color and are next to each other in any of the 4 directions.
#The border of a connected component is all the squares in the connected component that are either 4-directionally adjacent to a square not in the component, or on the boundary of the grid (the first or last row or column).
#You should color the border of the connected component that contains the square grid[row][col] with color.
#Return the final grid.


class Solution(object):
    def colorBorder(self, grid, row, col, color):
        """
        :type grid: List[List[int]]
        :type row: int
        :type col: int
        :type color: int
        :rtype: List[List[int]]
        """
        m = len(grid)
        n = len(grid[0])
        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] != grid[row][col]:
                return
            if i == 0 or i == m - 1 or j == 0 or j == n - 1 or grid[i + 1][j] != grid[row][col] or grid[i - 1][j] != grid[row][col] or grid[i][j + 1] != grid[row][col] or grid[i][j - 1] != grid[row][col]:
                grid[i][j] = color
            else:
                grid[i][j] = -grid[row][col]
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)
        dfs(row, col)
        for i in range(m):
            for j in range(n):
                if grid[i][j] < 0:
                    grid[i][j] = -grid[i][j]
        return grid
        

    