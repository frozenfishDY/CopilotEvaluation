#https://leetcode.com/problems/maximal-square/
#Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.


class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """       
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        if n == 0:
            return 0
        dp = [[0 for i in range(n)] for j in range(m)]
        res = 0
        for i in range(m):
            dp[i][0] = int(matrix[i][0])
            res = max(res, dp[i][0])
        for j in range(n):
            dp[0][j] = int(matrix[0][j])
            res = max(res, dp[0][j])
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == '1':
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
                    res = max(res, dp[i][j])
        return res * res
        

    