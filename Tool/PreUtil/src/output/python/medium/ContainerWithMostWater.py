#https://leetcode.com/problems/container-with-most-water/
#You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
#Find two lines that together with the x-axis form a container, such that the container contains the most water.
#Return the maximum amount of water a container can store.
#Notice that you may not slant the container.


class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
            
        res = 0
        i,j = 0,len(height)-1
        while i<j:
            res = max(res,(j-i)*min(height[i],height[j]))
            if height[i]<height[j]:
                i+=1
            else:
                j-=1
        return res
        

    