#https://leetcode.com/problems/minimum-number-of-refueling-stops/
#A car travels from a starting position to a destination which is target miles east of the starting position.
#There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.
#The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.
#Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.
#Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived.


class Solution(object):
    def minRefuelStops(self, target, startFuel, stations):
        """
        :type target: int
        :type startFuel: int
        :type stations: List[List[int]]
        :rtype: int
        """       
        if startFuel>=target:
            return 0
        if len(stations)==0:
            return -1
        dp=[0]*(len(stations)+1)
        dp[0]=startFuel
        for i in range(len(stations)):
            for j in range(i+1,-1,-1):
                if dp[j]>=stations[i][0]:
                    dp[j+1]=max(dp[j+1],dp[j]+stations[i][1])
        for i in range(len(dp)):
            if dp[i]>=target:
                return i
        return -1

        
        
    