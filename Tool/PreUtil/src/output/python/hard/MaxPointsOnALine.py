#https://leetcode.com/problems/max-points-on-a-line/
#Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.


class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        # initialize the maximum number of points
        max_points = 0
        # iterate over the points
        for i in range(len(points)):
            # initialize the slopes
            slopes = {}
            # initialize the duplicates
            duplicates = 0
            # iterate over the points
            for j in range(len(points)):
                # if the points are the same
                if points[i] == points[j]:
                    # increment the duplicates
                    duplicates += 1
                # if the points are not the same
                else:
                    # set the slope to the slope between the points
                    slope = self.getSlope(points[i], points[j])
                    # if the slope is not in the slopes
                    if slope not in slopes:
                        # set the slope to 1
                        slopes[slope] = 1
                    # if the slope is in the slopes
                    else:
                        # increment the slope
                        slopes[slope] += 1
            # set the maximum number of points to the maximum of the maximum number of points and the maximum of the slopes plus the duplicates
            max_points = max(max_points, max(slopes.values(), default=0) + duplicates)
        # return the maximum number of points
        return max_points
        
        
    