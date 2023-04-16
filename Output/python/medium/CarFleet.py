#https://leetcode.com/problems/car-fleet/
#There are n cars going to the same destination along a one-lane road. The destination is target miles away.
#You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).
#A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are assumed to have the same position).
#A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.
#If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.
#Return the number of car fleets that will arrive at the destination.


class Solution(object):
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        if not position:
            return 0
        cars = sorted(zip(position, speed))
        times = [(target - p) / float(s) for p, s in cars]
        res = 0
        cur = times[-1]
        for t in times[::-1]:
            if t > cur:
                res += 1
                cur = t
        return res
        

    