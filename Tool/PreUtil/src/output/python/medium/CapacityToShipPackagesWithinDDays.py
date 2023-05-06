#https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
#A conveyor belt has packages that must be shipped from one port to another within days days.
#The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
#Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.


class Solution(object):
    def shipWithinDays(self, weights, days):
        """
        :type weights: List[int]
        :type days: int
        :rtype: int
        """
        def canShip(weights, days, capacity):
            day = 1
            total = 0
            for weight in weights:
                total += weight
                if total > capacity:
                    day += 1
                    total = weight
            return day <= days
        
        left = max(weights)
        right = sum(weights)
        while left < right:
            mid = left + (right - left) // 2
            if canShip(weights, days, mid):
                right = mid
            else:
                left = mid + 1
        return left
        

    