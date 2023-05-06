#https://leetcode.com/problems/set-intersection-size-at-least-two/
#You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.
#A containing set is an array nums where each interval from intervals has at least two integers in nums.
#For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
#Return the minimum possible size of a containing set.


class Solution(object):
    def intersectionSizeTwo(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """       
        if not intervals:
            return 0
        intervals.sort(key=lambda x:x[1])
        result = []
        for i in range(len(intervals)):
            if not result:
                result.append(intervals[i][1]-1)
                result.append(intervals[i][1])
            else:
                if intervals[i][0]>result[-1]:
                    result.append(intervals[i][1]-1)
                    result.append(intervals[i][1])
                elif intervals[i][0]>result[-2]:
                    result.append(intervals[i][1])
        return len(result)

        
        
    