#https://leetcode.com/problems/angle-between-hands-of-a-clock/
#Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
#Answers within 10-5 of the actual value will be accepted as correct.
# 
#Example 1:
#Input: hour = 12, minutes = 30
#Output: 165
#Example 2:
#Input: hour = 3, minutes = 30
#Output: 75
#Example 3:
#Input: hour = 3, minutes = 15
#Output: 7.5
# 
#Constraints:
#	1 <= hour <= 12
#	0 <= minutes <= 59
class Solution(object):
    def angleClock(self, hour, minutes):
        """
        :type hour: int
        :type minutes: int
        :rtype: float
        """
        # Approach 1: Math
		# Runtime: 12 ms, faster than 95.09% of Python online submissions for Angle Between Hands of a Clock.
		# Memory Usage: 13.4 MB, less than 100.00% of Python online submissions for Angle Between Hands of a Clock.
        return min(abs(30 * hour + 0.5 * minutes - 6 * minutes), 360 - abs(30 * hour + 0.5 * minutes - 6 * minutes))
