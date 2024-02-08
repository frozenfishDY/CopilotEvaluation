#https://leetcode.com/problems/number-of-closed-islands/
#Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
#Return the number of closed islands.
# 
#Example 1:
#Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
#Output: 2
#Explanation: 
#Islands in gray are closed because they are completely surrounded by water (group of 1s).
#Example 2:
#Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
#Output: 1
#Example 3:
#Input: grid = [[1,1,1,1,1,1,1],
#               [1,0,0,0,0,0,1],
#               [1,0,1,1,1,0,1],
#               [1,0,1,0,1,0,1],
#               [1,0,1,1,1,0,1],
#               [1,0,0,0,0,0,1],
#               [1,1,1,1,1,1,1]]
#Output: 2
# 
#Constraints:
#	1 <= grid.length, grid[0].length <= 100
#	0 <= grid[i][j] <=1
class Solution(object):
    def closedIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # Approach 1: DFS
		# Runtime: 156 ms, faster than 53.85% of Python online submissions for Number of Closed Islands.
		# Memory Usage: 13.6 MB, less than 100.00% of Python online submissions for Number of Closed Islands.
        rows, cols = len(grid), len(grid[0])
        def dfs(i, j):
            if not 0 <= i < rows or not 0 <= j < cols:
                return False
            if grid[i][j] == 1:
                return True
            grid[i][j] = 1
            return dfs(i + 1, j) & dfs(i - 1, j) & dfs(i, j + 1) & dfs(i, j - 1)
        ans = 0
        for i in range(rows):
            for j in range(cols):
                ans += dfs(i, j)
        return ans