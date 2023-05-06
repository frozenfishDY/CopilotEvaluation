#https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
#Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.


class Solution(object):
    def maxSideLength(self, mat, threshold):
        """
        :type mat: List[List[int]]
        :type threshold: int
        :rtype: int
        """
        res = 0
        dp = [[0]*(len(mat[0])+1) for _ in range(len(mat)+1)]
        for i in range(1,len(mat)+1):
            for j in range(1,len(mat[0])+1):
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1]
                if i >= res and j >= res and dp[i][j] - dp[i-res][j] - dp[i][j-res] + dp[i-res][j-res] <= threshold:
                    res += 1
        return res
        

    