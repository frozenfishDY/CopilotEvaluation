#https://leetcode.com/problems/diagonal-traverse/
#Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
# 
#Example 1:
#Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
#Output: [1,2,4,7,5,3,6,8,9]
#Example 2:
#Input: mat = [[1,2],[3,4]]
#Output: [1,2,3,4]
# 
#Constraints:
#	m == mat.length
#	n == mat[i].length
#	1 <= m, n <= 104
#	1 <= m * n <= 104
#	-105 <= mat[i][j] <= 105
class Solution(object):
    def findDiagonalOrder(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        #Solution
        #1. For each element in matrix, add the element to the result
        #2. If the sum of row and column is even, add the element to the result
        #3. Return the result
        #
        #Example:
        #mat: [[1,2,3],[4,5,6],[7,8,9]]
        #ret: [1,2,4,7,5,3,6,8,9]
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