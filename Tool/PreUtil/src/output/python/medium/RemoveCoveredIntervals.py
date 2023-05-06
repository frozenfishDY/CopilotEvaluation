#https://leetcode.com/problems/remove-covered-intervals/
#Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
#The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
#Return the number of remaining intervals.


class Solution(object):
    def removeCoveredIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort(key=lambda x:x[0])
        res = 0
        right = 0
        for i in range(len(intervals)):
            if intervals[i][1] > right:
                res += 1
                right = intervals[i][1]
        return res
        

    