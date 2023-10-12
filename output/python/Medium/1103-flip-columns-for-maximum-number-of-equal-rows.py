#https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
#You are given an m x n binary matrix matrix.
#You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
#Return the maximum number of rows that have all values equal after some number of flips.
# 
#Example 1:
#Input: matrix = [[0,1],[1,1]]
#Output: 1
#Explanation: After flipping no values, 1 row has all values equal.
#Example 2:
#Input: matrix = [[0,1],[1,0]]
#Output: 2
#Explanation: After flipping values in the first column, both rows have equal values.
#Example 3:
#Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
#Output: 2
#Explanation: After flipping values in the first two columns, the last two rows have equal values.
# 
#Constraints:
#	m == matrix.length
#	n == matrix[i].length
#	1 <= m, n <= 300
#	matrix[i][j] is either 0 or 1.
class Solution(object):
    def maxEqualRowsAfterFlips(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        #Solution
        #1. Initialize the result to 0
        #2. For each number in matrix, check if it is 1
        #3. If it is, check if the number is surrounded by 0's
        #4. If it is, increase the result by 1
        #5. Return the result
        #
        #Example:
        #matrix: [[0,1],[1,1]]
        #ret: 1
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)
        
        ret = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 1:
                    if self.check(matrix, i, j):
                        ret += 1
        return ret