#https://leetcode.com/problems/making-a-large-island/
#You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1._x000D_
#_x000D_
#Return the size of the largest island in grid after applying this operation._x000D_
#_x000D_
#An island is a 4-directionally connected group of 1s._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#Input: grid = [[1,0],[0,1]]_x000D_
#Output: 3_x000D_
#Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3._x000D_
#_x000D_
#_x000D_
#Example 2:_x000D_
#_x000D_
#_x000D_
#Input: grid = [[1,1],[1,0]]_x000D_
#Output: 4_x000D_
#Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4._x000D_
#_x000D_
#Example 3:_x000D_
#_x000D_
#_x000D_
#Input: grid = [[1,1],[1,1]]_x000D_
#Output: 4_x000D_
#Explanation: Can't change any 0 to 1, only one island with area = 4._x000D_
#_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	n == grid.length_x000D_
#	n == grid[i].length_x000D_
#	1 <= n <= 500_x000D_
#	grid[i][j] is either 0 or 1._x000D_
class Solution(object):
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        