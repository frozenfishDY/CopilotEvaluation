#https://leetcode.com/problems/determine-if-two-events-have-conflict/
#You are given two arrays of strings that represent two inclusive events that happened on the same day, event1 and event2, where:
#	event1 = [startTime1, endTime1] and
#	event2 = [startTime2, endTime2].
#Event times are valid 24 hours format in the form of HH:MM.
#A conflict happens when two events have some non-empty intersection (i.e., some moment is common to both events).
#Return true if there is a conflict between two events. Otherwise, return false.
# 
#Example 1:
#Input: event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
#Output: true
#Explanation: The two events intersect at time 2:00.
#Example 2:
#Input: event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
#Output: true
#Explanation: The two events intersect starting from 01:20 to 02:00.
#Example 3:
#Input: event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
#Output: false
#Explanation: The two events do not intersect.
# 
#Constraints:
#	evnet1.length == event2.length == 2.
#	event1[i].length == event2[i].length == 5
#	startTime1 <= endTime1
#	startTime2 <= endTime2
#	All the event times follow the HH:MM format.
class Solution(object):
    def haveConflict(self, event1, event2):
        """
        :type event1: List[str]
        :type event2: List[str]
        :rtype: bool
        """
        def convert(time):
            return int(time[:2]) * 60 + int(time[3:])
        return max(convert(event1[0]), convert(event2[0])) < min(convert(event1[1]), convert(event2[1]))
