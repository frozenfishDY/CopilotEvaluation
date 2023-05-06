#https://leetcode.com/problems/largest-rectangle-in-histogram/
#Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.


class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        # initialize the stack
        stack = []
        # initialize the maximum area
        max_area = 0
        # iterate over the heights
        for i in range(len(heights)):
            # if the stack is not empty and the current height is less than the height at the top of the stack
            while stack and heights[i] < heights[stack[-1]]:
                # set the top of the stack to the current height
                top = stack.pop()
                # if the stack is not empty
                if stack:
                    # set the width to the current index minus the index at the top of the stack minus 1
                    width = i - stack[-1] - 1
                # if the stack is empty
                else:
                    # set the width to the current index
                    width = i
                # set the maximum area to the maximum of the maximum area and the height at the top of the stack times the width
                max_area = max(max_area, heights[top] * width)
            # push the current index onto the stack
            stack.append(i)
        # iterate over the stack
        while stack:
            # set the top of the stack to the current height
            top = stack.pop()
            # if the stack is not empty
            if stack:
                # set the width to the current index minus the index at the top of the stack minus 1
                width = len(heights) - stack[-1] - 1
            # if the stack is empty
            else:
                # set the width to the current index
                width = len(heights)
            # set the maximum area to the maximum of the maximum area and the height at the top of the stack times the width
            max_area = max(max_area, heights[top] * width)
        # return the maximum area
        return max_area
        
        
    