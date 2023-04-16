#https://leetcode.com/problems/perfect-rectangle/
#Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).
#Return true if all the rectangles together form an exact cover of a rectangular region.


class Solution(object):
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """      
        if not rectangles:
            return False
        if len(rectangles) == 1:
            return True
        # get the left, bottom, right, top
        left = rectangles[0][0]
        bottom = rectangles[0][1]
        right = rectangles[0][2]
        top = rectangles[0][3]
        # get the area
        area = 0
        # initialize the set
        s = set()
        # iterate over the rectangles
        for rectangle in rectangles:
            # get the left, bottom, right, top
            left = min(left, rectangle[0])
            bottom = min(bottom, rectangle[1])
            right = max(right, rectangle[2])
            top = max(top, rectangle[3])
            # get the area
            area += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1])
            # get the bottom left, bottom right, top left, top right
            bottom_left = (rectangle[0], rectangle[1])
            bottom_right = (rectangle[2], rectangle[1])
            top_left = (rectangle[0], rectangle[3])
            top_right = (rectangle[2], rectangle[3])
            # if the bottom left is in the set
            if bottom_left in s:
                # remove the bottom left from the set
                s.remove(bottom_left)
            # if the bottom left is not in the set
            else:
                # add the bottom left to the set
                s.add(bottom_left)
            # if the bottom right is in the set
            if bottom_right in s:
                # remove the bottom right from the set
                s.remove(bottom_right)
            # if the bottom right is not in the set
            else:
                # add the bottom right to the set
                s.add(bottom_right)
            # if the top left is in the set
            if top_left in s:
                # remove the top left from the set
                s.remove(top_left)
            # if the top left is not in the set
            else:
                # add the top left to the set
                s.add(top_left)
            # if the top right is in the set
            if top_right in s:
                # remove the top right from the set
                s.remove(top_right)
            # if the top right is not in the set
            else:
                # add the top right to the set
                s.add(top_right)
        # if the area is not equal to the area of the rectangle
        if area != (right - left) * (top - bottom):
            # return false
            return False

        
        
    