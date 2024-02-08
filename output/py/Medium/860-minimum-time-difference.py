#https://leetcode.com/problems/minimum-time-difference/
#Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
# 
#Example 1:
#Input: timePoints = ["23:59","00:00"]
#Output: 1
#Example 2:
#Input: timePoints = ["00:00","23:59","00:00"]
#Output: 0
# 
#Constraints:
#	2 <= timePoints.length <= 2 * 104
#	timePoints[i] is in the format "HH:MM".
class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        #Solution
        #1. Convert each time to minutes
        #2. Sort the times
        #3. Find the minimum difference between each pair of times
        #4. Return the minimum difference
        #
        #Example:
        #timePoints: ["23:59","00:00"]
        #ret: 1
        #
        #Time complexity: O(nlogn)
        #Space complexity: O(n)
        def convert_to_minutes(time):
            hours, minutes = time.split(":")
            return int(hours) * 60 + int(minutes)

        times = sorted(map(convert_to_minutes, timePoints))
        times.append(times[0] + 24 * 60)
        return min(times[i + 1] - times[i] for i in range(len(times) - 1))
