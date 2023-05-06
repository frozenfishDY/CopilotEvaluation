#https://leetcode.com/problems/island-perimeter/
#You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
#Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
#The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.


class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """ 
        if len(grid)==0:
            return 0
        if len(grid[0])==0:
            return 0
        res=0
        for i in range(0,len(grid)):
            for j in range(0,len(grid[0])):
                if grid[i][j]==1:
                    if i==0:
                        res+=1
                    if i==len(grid)-1:
                        res+=1
                    if j==0:
                        res+=1
                    if j==len(grid[0])-1:
                        res+=1
                    if i>0 and grid[i-1][j]==0:
                        res+=1
                    if i<len(grid)-1 and grid[i+1][j]==0:
                        res+=1
                    if j>0 and grid[i][j-1]==0:
                        res+=1
                    if j<len(grid[0])-1 and grid[i][j+1]==0:
                        res+=1
        return res

    