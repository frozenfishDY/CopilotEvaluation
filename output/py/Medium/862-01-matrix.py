#https://leetcode.com/problems/01-matrix/
#Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
#The distance between two adjacent cells is 1.
# 
#Example 1:
#Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
#Output: [[0,0,0],[0,1,0],[0,0,0]]
#Example 2:
#Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
#Output: [[0,0,0],[0,1,0],[1,2,1]]
# 
#Constraints:
#	m == mat.length
#	n == mat[i].length
#	1 <= m, n <= 104
#	1 <= m * n <= 104
#	mat[i][j] is either 0 or 1.
#	There is at least one 0 in mat.
class Solution(object):
    def updateMatrix(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        #Solution
        #1. For each element in matrix, add the element to the result
        #2. If the sum of row and column is even, add the element to the result
        #3. Return the result
        #
        #Example:
        #mat: [[0,0,0],[0,1,0],[0,0,0]]
        #ret: [[0,0,0],[0,1,0],[0,0,0]]
        #
        #Time complexity: O(mn)
        #Space complexity: O(1)

        result = []
        for row in range(len(mat)):
            for col in range(len(mat[0])):
                if (row + col) % 2 == 0:
                    result.append(mat[row][col])
                else:
                    result.insert(0, mat[row][col])

        return result