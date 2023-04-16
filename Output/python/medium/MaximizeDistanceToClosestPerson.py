#https://leetcode.com/problems/maximize-distance-to-closest-person/
#You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).
#There is at least one empty seat, and at least one person sitting.
#Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
#Return that maximum distance to the closest person.


class Solution(object):
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        res = 0
        left = 0
        right = len(seats) - 1
        while left < len(seats) and seats[left] == 0:
            left += 1
        while right >= 0 and seats[right] == 0:
            right -= 1
        res = max(res, left, len(seats) - right - 1)
        i = left
        while i < right:
            if seats[i] == 1:
                i += 1
            else:
                j = i + 1
                while j < right and seats[j] == 0:
                    j += 1
                res = max(res, (j - i + 1) // 2)
                i = j
        return res
        

    