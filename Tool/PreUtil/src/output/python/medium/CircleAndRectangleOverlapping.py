#https://leetcode.com/problems/circle-and-rectangle-overlapping/
#You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.
#Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.


class Solution(object):
    def checkOverlap(self, radius, xCenter, yCenter, x1, y1, x2, y2):
        """
        :type radius: int
        :type xCenter: int
        :type yCenter: int
        :type x1: int
        :type y1: int
        :type x2: int
        :type y2: int
        :rtype: bool
        """       
        # 1. Find the closest point to the center of the circle
        # 2. Check if the distance between the closest point and the center is less than or equal to the radius
        # 3. If the distance is less than or equal to the radius, then return true
        # 4. If the distance is greater than the radius, then return false
        closest_x = xCenter
        closest_y = yCenter
        if xCenter < x1:
            closest_x = x1
        elif xCenter > x2:
            closest_x = x2
        if yCenter < y1:
            closest_y = y1
        elif yCenter > y2:
            closest_y = y2
        distance = math.sqrt((closest_x - xCenter) ** 2 + (closest_y - yCenter) ** 2)
        if distance <= radius:
            return True
        else:
            return False

        

    