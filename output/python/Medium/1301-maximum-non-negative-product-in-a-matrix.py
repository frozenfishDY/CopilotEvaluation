#https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
#You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
#Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
#Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.
#Notice that the modulo is performed after getting the maximum product.
# 
#Example 1:
#Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
#Output: -1
#Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
#Example 2:
#Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
#Output: 8
#Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).
#Example 3:
#Input: grid = [[1,3],[0,-4]]
#Output: 0
#Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 15
#	-4 <= grid[i][j] <= 4
class Solution(object):
    def maxProductPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        mod = 10 ** 9 + 7
        dp = [[[0, 0] for j in range(n)] for i in range(m)]
        dp[0][0] = [grid[0][0], grid[0][0]]
        for i in range(1, m):
            dp[i][0] = [dp[i - 1][0][0] * grid[i][0], dp[i - 1][0][1] * grid[i][0]]
        for j in range(1, n):
            dp[0][j] = [dp[0][j - 1][0] * grid[0][j], dp[0][j - 1][1] * grid[0][j]]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = [max(dp[i - 1][j][0], dp[i][j - 1][0]) * grid[i][j], min(dp[i - 1][j][1], dp[i][j - 1][1]) * grid[i][j]]
        return dp[m - 1][n - 1][0] % mod if dp[m - 1][n - 1][0] >= 0 else -1
