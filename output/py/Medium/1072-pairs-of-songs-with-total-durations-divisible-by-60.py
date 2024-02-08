#https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
#You are given a list of songs where the ith song has a duration of time[i] seconds.
#Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.


class Solution(object):
    def numPairsDivisibleBy60(self, time):
        """
        :type time: List[int]
        :rtype: int
        """                                                                        
        res = 0
        count = [0]*60
        for t in time:
            res += count[(60-t%60)%60]
            count[t%60] += 1
        return res

        

    