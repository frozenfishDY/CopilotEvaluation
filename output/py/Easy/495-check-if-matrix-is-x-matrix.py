#https://leetcode.com/problems/check-if-matrix-is-x-matrix/
#A square matrix is said to be an X-Matrix if both of the following conditions hold:
#	All the elements in the diagonals of the matrix are non-zero.
#	All other elements are 0.
#Given a 2D integer array grid of size n x n representing a square matrix, return true if grid is an X-Matrix. Otherwise, return false.
# 
#Example 1:
#Input: grid = [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
#Output: true
#Explanation: Refer to the diagram above. 
#An X-Matrix should have the green elements (diagonals) be non-zero and the red elements be 0.
#Thus, grid is an X-Matrix.
#Example 2:
#Input: grid = [[5,7,0],[0,3,1],[0,5,0]]
#Output: false
#Explanation: Refer to the diagram above.
#An X-Matrix should have the green elements (diagonals) be non-zero and the red elements be 0.
#Thus, grid is not an X-Matrix.
# 
#Constraints:
#	n == grid.length == grid[i].length
#	3 <= n <= 100
#	0 <= grid[i][j] <= 105
class Solution(object):
    def checkXMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        return all([grid[i][i]!=0 and grid[i][len(grid)-1-i]!=0 and grid[i][j]==0 for i in range(len(grid)) for j in range(len(grid)) if i!=j and i!=len(grid)-1-j])
