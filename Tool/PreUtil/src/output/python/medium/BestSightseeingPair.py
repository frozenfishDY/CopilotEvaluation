#https://leetcode.com/problems/best-sightseeing-pair/
#You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
#The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
#Return the maximum score of a pair of sightseeing spots.


class Solution(object):
    def maxScoreSightseeingPair(self, values):
        """
        :type values: List[int]
        :rtype: int
        """
        res = 0
        mx = values[0]
        for i in range(1,len(values)):
            res = max(res,mx+values[i]-i)
            mx = max(mx,values[i]+i)
        return res
        

    