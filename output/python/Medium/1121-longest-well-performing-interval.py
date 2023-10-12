#https://leetcode.com/problems/longest-well-performing-interval/
#We are given hours, a list of the number of hours worked per day for a given employee.
#A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.
#A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.
#Return the length of the longest well-performing interval.
# 
#Example 1:
#Input: hours = [9,9,6,0,6,6,9]
#Output: 3
#Explanation: The longest well-performing interval is [9,9,6].
#Example 2:
#Input: hours = [6,6,6]
#Output: 0
# 
#Constraints:
#	1 <= hours.length <= 104
#	0 <= hours[i] <= 16
class Solution(object):
    def longestWPI(self, hours):
        """
        :type hours: List[int]
        :rtype: int
        """
        # Approach 1: Prefix Sum + Hashmap
        # Time Complexity: O(N)
        # Space Complexity: O(N)
        # Runtime: 192 ms, faster than 80.14% of Python3 online submissions for Longest Well-Performing Interval.
        # Memory Usage: 17.7 MB, less than 6.97% of Python3 online submissions for Longest Well-Performing Interval.
        ans, score = 0, 0
        seen = {0: -1}
        for i, hour in enumerate(hours):
            score = score + 1 if hour > 8 else score - 1
            if score > 0:
                ans = max(ans, i + 1)
            elif score - 1 in seen:
                ans = max(ans, i - seen[score - 1])
            if score not in seen:
                seen[score] = i
        return ans