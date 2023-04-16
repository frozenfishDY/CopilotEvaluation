#https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
#You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).
#You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.
#Return the smallest possible total score that you can achieve with some triangulation of the polygon.


class Solution(object):
    def minScoreTriangulation(self, values):
        """
        :type values: List[int]
        :rtype: int
        """
        n = len(values)
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 2, n):
                dp[i][j] = min(dp[i][k] + dp[k][j] + values[i] * values[j] * values[k] for k in range(i + 1, j))
        return dp[0][n - 1]
        

    