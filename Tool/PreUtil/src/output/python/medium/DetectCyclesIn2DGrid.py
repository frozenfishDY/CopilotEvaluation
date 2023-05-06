#https://leetcode.com/problems/detect-cycles-in-2d-grid/
#Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
#A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.
#Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.
#Return true if any cycle of the same value exists in grid, otherwise, return false.


class Solution(object):
    def containsCycle(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: bool
        """
        # 1. Loop through the grid
        # 2. If the current cell is not visited, then call the dfs function
        # 3. Return the result of the dfs function
        visited = {}
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (i, j) not in visited:
                    if self.dfs(grid, i, j, visited, None):
                        return True
        return False
        

    