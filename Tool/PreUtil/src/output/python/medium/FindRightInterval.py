#https://leetcode.com/problems/find-right-interval/
#You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
#The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.
#Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.


class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[int]
        """
        res = []
        for i in range(len(intervals)):
            min_start = float('inf')
            min_index = -1
            for j in range(len(intervals)):
                if intervals[j][0] >= intervals[i][1] and intervals[j][0] < min_start:
                    min_start = intervals[j][0]
                    min_index = j
            res.append(min_index)
        return res
        

    