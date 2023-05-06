#https://leetcode.com/problems/rectangle-area-ii/
#You are given a 2D array of axis-aligned rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] denotes the ith rectangle where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner.
#Calculate the total area covered by all rectangles in the plane. Any area covered by two or more rectangles should only be counted once.
#Return the total area. Since the answer may be too large, return it modulo 10^9 + 7.


class Solution(object):
    def rectangleArea(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """
        if len(rectangles)==1:
            return (rectangles[0][2]-rectangles[0][0])*(rectangles[0][3]-rectangles[0][1])
        result=0
        for i in range(len(rectangles)):
            result+=self.rectangleAreaHelper(rectangles,i)
        return result
        
        
    