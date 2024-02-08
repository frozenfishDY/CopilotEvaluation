#https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
#Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
#Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
#Return the minimum time Bob needs to make the rope colorful.


class Solution(object):
    def minCost(self, colors, neededTime):
        """
        :type colors: str
        :type neededTime: List[int]
        :rtype: int
        """
        if len(colors)==1:
            return neededTime[0]
        if len(colors)==2:
            if colors[0]==colors[1]:
                return min(neededTime[0],neededTime[1])
            else:
                return neededTime[0]+neededTime[1]
        if colors[0]==colors[1]:
            return min(neededTime[0]+self.minCost(colors[1:],neededTime[1:]),self.minCost(colors[1:],neededTime[1:]))
        else:
            return neededTime[0]+self.minCost(colors[1:],neededTime[1:])
        

    