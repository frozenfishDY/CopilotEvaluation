#https://leetcode.com/problems/cyclically-rotating-a-grid/
#You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k._x000D_
#_x000D_
#The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:_x000D_
#_x000D_
#_x000D_
#_x000D_
#A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:_x000D_
#_x000D_
#Return the matrix after applying k cyclic rotations to it._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#Input: grid = [[40,10],[30,20]], k = 1_x000D_
#Output: [[10,20],[40,30]]_x000D_
#Explanation: The figures above represent the grid at every state._x000D_
#_x000D_
#_x000D_
#Example 2:_x000D_
#  _x000D_
#_x000D_
#_x000D_
#Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2_x000D_
#Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]_x000D_
#Explanation: The figures above represent the grid at every state._x000D_
#_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	m == grid.length_x000D_
#	n == grid[i].length_x000D_
#	2 <= m, n <= 50_x000D_
#	Both m and n are even integers._x000D_
#	1 <= grid[i][j] <= 5000_x000D_
#	1 <= k <= 109_x000D_
class Solution(object):
    def rotateGrid(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """  
        m, n = len(grid), len(grid[0])
        for i in range(min(m, n) / 2):
            x, y = i, i
            l = (m + n - 2 - 4 * i) * 2
            k = k % l
            for j in range(k):
                tmp = grid[x][y]
                for p in range(x, m - 1 - i):
                    grid[p][y] = grid[p + 1][y]
                for p in range(y, n - 1 - i):
                    grid[m - 1 - i][p] = grid[m - 1 - i][p + 1]
                for p in range(m - 1 - i, x, -1):
                    grid[p][n - 1 - i] = grid[p - 1][n - 1 - i]
                for p in range(n - 1 - i, y, -1):
                    grid[x][p] = grid[x][p - 1]
                grid[x][y + 1] = tmp
        return grid