#https://leetcode.com/problems/max-area-of-island/
#You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
#The area of an island is the number of cells with a value 1 in the island.
#Return the maximum area of an island in grid. If there is no island, return 0.
# 
#Example 1:
#Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
#Output: 6
#Explanation: The answer is not 11, because the island must be connected 4-directionally.
#Example 2:
#Input: grid = [[0,0,0,0,0,0,0,0]]
#Output: 0
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 50
#	grid[i][j] is either 0 or 1.
class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """   
        #Solution
        #1. Initialize the result to 0
        #2. For each number in grid, check if it is 1
        #3. If it is, check if the number is surrounded by 0's
        #4. If it is, increase the result by 1
        #5. Return the result
        #
        #Example:
        #grid: [[0,0,1,0,0,0,0,1,0,0,0,0,0],
        #       [0,0,0,0,0,0,0,1,1,1,0,0,0],
        #       [0,1,1,0,1,0,0,0,0,0,0,0,0],
        #       [0,1,0,0,1,1,0,0,1,0,1,0,0],
        #       [0,1,0,0,1,1,0,0,1,1,1,0,0],
        #       [0,0,0,0,0,0,0,0,0,0,1,0,0],
        #       [0,0,0,0,0,0,0,1,1,1,0,0,0],
        #       [0,0,0,0,0,0,0,1,1,0,0,0,0]]
        #ret: 6
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        
        ret = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    if self.check(grid, i, j):
                        ret += 1
        return ret
        