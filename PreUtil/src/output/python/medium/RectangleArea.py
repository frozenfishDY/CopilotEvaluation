#https://leetcode.com/problems/rectangle-area/
#Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
#The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
#The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).


class Solution(object):
    def computeArea(self, ax1, ay1, ax2, ay2, bx1, by1, bx2, by2):
        """
        :type ax1: int
        :type ay1: int
        :type ax2: int
        :type ay2: int
        :type bx1: int
        :type by1: int
        :type bx2: int
        :type by2: int
        :rtype: int
        """
        x1 = max(ax1, bx1)
        x2 = min(ax2, bx2)
        y1 = max(ay1, by1)
        y2 = min(ay2, by2)
        if x1 < x2 and y1 < y2:
            overlap = (x2 - x1) * (y2 - y1)
        else:
            overlap = 0
        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - overlap
        

    