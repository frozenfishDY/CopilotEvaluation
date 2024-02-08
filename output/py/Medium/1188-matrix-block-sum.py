#https://leetcode.com/problems/matrix-block-sum/
#Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
#	i - k <= r <= i + k,
#	j - k <= c <= j + k, and
#	(r, c) is a valid position in the matrix.
# 
#Example 1:
#Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
#Output: [[12,21,16],[27,45,33],[24,39,28]]
#Example 2:
#Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
#Output: [[45,45,45],[45,45,45],[45,45,45]]
# 
#Constraints:
#	m == mat.length
#	n == mat[i].length
#	1 <= m, n, k <= 100
#	1 <= mat[i][j] <= 100
class Solution(object):
    def matrixBlockSum(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        # Approach 1: Brute Force
		# Runtime: 5232 ms, faster than 5.03% of Python online submissions for Matrix Block Sum.
		# Memory Usage: 14.4 MB, less than 100.00% of Python online submissions for Matrix Block Sum.
        rows, cols = len(mat), len(mat[0])
        ans = [[0] * cols for _ in range(rows)]
        for i in range(rows):
            for j in range(cols):
                for x in range(max(0, i - k), min(rows, i + k + 1)):
                    for y in range(max(0, j - k), min(cols, j + k + 1)):
                        ans[i][j] += mat[x][y]
        return ans