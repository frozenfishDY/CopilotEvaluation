#https://leetcode.com/problems/trapping-rain-water/
#Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height:
            return 0
        if len(height)==1:
            return 0
        res=0
        left_max=[0]*len(height)
        right_max=[0]*len(height)
        left_max[0]=height[0]
        right_max[-1]=height[-1]
        for i in range(1,len(height)):
            left_max[i]=max(left_max[i-1],height[i])
        for i in range(len(height)-2,-1,-1):
            right_max[i]=max(right_max[i+1],height[i])
        for i in range(1,len(height)-1):
            res=res+min(left_max[i],right_max[i])-height[i]
        return res
        
    