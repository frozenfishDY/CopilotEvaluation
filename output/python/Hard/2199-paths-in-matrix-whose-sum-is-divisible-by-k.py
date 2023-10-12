#https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
#You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.
#Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.
# 
#Example 1:
#Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
#Output: 2
#Explanation: There are two paths where the sum of the elements on the path is divisible by k.
#The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
#The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.
#Example 2:
#Input: grid = [[0,0]], k = 5
#Output: 1
#Explanation: The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.
#Example 3:
#Input: grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
#Output: 10
#Explanation: Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 5 * 104
#	1 <= m * n <= 5 * 104
#	0 <= grid[i][j] <= 100
#	1 <= k <= 50
class Solution(object):
    def numberOfPaths(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = grid[0][0]
        for i in range(1, n):
            dp[0][i] = grid[0][i] + dp[0][i - 1]
        for i in range(1, m):
            dp[i][0] = grid[i][0] + dp[i - 1][0]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = grid[i][j] + (dp[i - 1][j] + dp[i][j - 1]) % k
        return dp[m - 1][n - 1] % k