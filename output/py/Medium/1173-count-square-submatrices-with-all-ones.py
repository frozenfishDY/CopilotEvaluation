#https://leetcode.com/problems/count-square-submatrices-with-all-ones/
#Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
# 
#Example 1:
#Input: matrix =
#[
#  [0,1,1,1],
#  [1,1,1,1],
#  [0,1,1,1]
#]
#Output: 15
#Explanation: 
#There are 10 squares of side 1.
#There are 4 squares of side 2.
#There is  1 square of side 3.
#Total number of squares = 10 + 4 + 1 = 15.
#Example 2:
#Input: matrix = 
#[
#  [1,0,1],
#  [1,1,0],
#  [1,1,0]
#]
#Output: 7
#Explanation: 
#There are 6 squares of side 1.  
#There is 1 square of side 2. 
#Total number of squares = 6 + 1 = 7.
# 
#Constraints:
#	1 <= arr.length <= 300
#	1 <= arr[0].length <= 300
#	0 <= arr[i][j] <= 1
class Solution(object):
    def countSquares(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        # Approach 1: Dynamic Programming
        # Time Complexity: O(N^2)
        # Space Complexity: O(N^2)
        # Runtime: 676 ms, faster than 84.85% of Python online submissions for Count Square Submatrices with All Ones.
        # Memory Usage: 16.4 MB, less than 100.00% of Python online submissions for Count Square Submatrices with All Ones.
        ans = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i and j and matrix[i][j]:
                    matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1
                ans += matrix[i][j]
        return ans