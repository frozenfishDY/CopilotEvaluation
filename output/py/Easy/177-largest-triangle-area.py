#https://leetcode.com/problems/largest-triangle-area/
#Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.
# 
#Example 1:
#Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
#Output: 2.00000
#Explanation: The five points are shown in the above figure. The red triangle is the largest.
#Example 2:
#Input: points = [[1,0],[0,0],[0,1]]
#Output: 0.50000
# 
#Constraints:
#	3 <= points.length <= 50
#	-50 <= xi, yi <= 50
#	All the given points are unique.
class Solution(object):
    def largestTriangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        from itertools import combinations
        def area(p, q, r):
            return .5 * abs(p[0]*q[1]+q[0]*r[1]+r[0]*p[1]-p[1]*q[0]-q[1]*r[0]-r[1]*p[0])
        return max(area(*triangle) for triangle in combinations(points, 3))
