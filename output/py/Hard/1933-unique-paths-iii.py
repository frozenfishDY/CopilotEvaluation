#https://leetcode.com/problems/unique-paths-iii/
#You are given an m x n integer array grid where grid[i][j] could be:
#1 representing the starting square. There is exactly one starting square.
#2 representing the ending square. There is exactly one ending square.
#0 representing empty squares we can walk over.
#-1 representing obstacles that we cannot walk over.
#Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.


class Solution(object):
    def uniquePathsIII(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0
        if len(grid)==1:
            return 1
        if len(grid)==2:
            return 2
        result = 0
        for i in range(len(grid)):
            result = max(result,self.uniquePathsIII(grid[:i]+grid[i+1:]))
        return result
        
        
    