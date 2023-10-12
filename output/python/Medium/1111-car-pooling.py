#https://leetcode.com/problems/car-pooling/
#There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
#You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.
#Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
# 
#Example 1:
#Input: trips = [[2,1,5],[3,3,7]], capacity = 4
#Output: false
#Example 2:
#Input: trips = [[2,1,5],[3,3,7]], capacity = 5
#Output: true
# 
#Constraints:
#	1 <= trips.length <= 1000
#	trips[i].length == 3
#	1 <= numPassengersi <= 100
#	0 <= fromi < toi <= 1000
#	1 <= capacity <= 105
class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        #Solution
        #1. Initialize the result to 0
        #2. For each number in trips, check if it is greater than the last number in each subsequence
        #3. If it is, add the new subsequence to the result
        #4. Return the result
        #
        #Example:
        #trips: [[2,1,5],[3,3,7]]
        #ret: false
        #
        #Time complexity: O(n^2)
        #Space complexity: O(n)

        ret = 0
        for num in trips:
            for i in range(len(ret)):
                if num > ret[i]:
                    ret[i] = num

        return ret