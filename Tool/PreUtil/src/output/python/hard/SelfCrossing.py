#https://leetcode.com/problems/self-crossing/
#You are given an array of integers distance.
#You start at the point (0, 0) on an X-Y plane, and you move distance[0] meters to the north, then distance[1] meters to the west, distance[2] meters to the south, distance[3] meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.
#Return true if your path crosses itself or false if it does not.


class Solution(object):
    def isSelfCrossing(self, distance):
        """
        :type distance: List[int]
        :rtype: bool
        """
        if not distance:
            return False
        if len(distance) < 4:
            return False
        for i in range(3,len(distance)):
            if distance[i] >= distance[i-2] and distance[i-1] <= distance[i-3]:
                return True
            if i >= 4 and distance[i-1] == distance[i-3] and distance[i] >= distance[i-2] - distance[i-4]:
                return True
            if i >= 5 and distance[i-2] >= distance[i-4] and distance[i-3] >= distance[i-1] and distance[i] >= distance[i-2] - distance[i-4] and distance[i-1] >= distance[i-3] - distance[i-5]:
                return True
        return False
        
        
    