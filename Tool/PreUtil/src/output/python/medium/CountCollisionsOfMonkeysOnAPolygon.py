#https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/
#There is a regular convex polygon with n vertices. The vertices are labeled from 0 to n - 1 in a clockwise direction, and each vertex has exactly one monkey. The following figure shows a convex polygon of 6 vertices.
#Each monkey moves simultaneously to a neighboring vertex. A neighboring vertex for a vertex i can be:
#the vertex (i + 1) % n in the clockwise direction, or
#the vertex (i - 1 + n) % n in the counter-clockwise direction.
#A collision happens if at least two monkeys reside on the same vertex after the movement or intersect on an edge.
#Return the number of ways the monkeys can move so that at least one collision happens. Since the answer may be very large, return it modulo 109 + 7.
#Note that each monkey can only move once.


class Solution(object):
    def monkeyMove(self, n):
        """
        :type n: int
        :rtype: int
        """       
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n + 1):
            dp[i] = (dp[i - 1] + dp[i - 2]) * (i - 1)
        return dp[n]

        

    