#https://leetcode.com/problems/maximal-rectangle/
#Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.


class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """       
        if not matrix:
            return 0
        max_area = 0
        heights = [0] * len(matrix[0])
        for row in matrix:
            for i in range(len(row)):
                if row[i] == '1':
                    heights[i] += 1
                else:
                    heights[i] = 0
            max_area = max(max_area, self.largestRectangleArea(heights))
        return max_area

        
        
    