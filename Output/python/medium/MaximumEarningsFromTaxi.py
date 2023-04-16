#https://leetcode.com/problems/maximum-earnings-from-taxi/
#There are n points on a road you are driving your taxi on. The n points on the road are labeled from 1 to n in the direction you are going, and you want to drive from point 1 to point n to make money by picking up passengers. You cannot change the direction of the taxi.
#The passengers are represented by a 0-indexed 2D integer array rides, where rides[i] = [starti, endi, tipi] denotes the ith passenger requesting a ride from point starti to point endi who is willing to give a tipi dollar tip.
#For each passenger i you pick up, you earn endi - starti + tipi dollars. You may only drive at most one passenger at a time.
#Given n and rides, return the maximum number of dollars you can earn by picking up the passengers optimally.
#Note: You may drop off a passenger and pick up a different passenger at the same point.


class Solution(object):
    def maxTaxiEarnings(self, n, rides):
        """
        :type n: int
        :type rides: List[List[int]]
        :rtype: int
        """
        rides.sort()
        dp = [0] * (n + 1)
        for i in range(len(rides)):
            start, end, tip = rides[i]
            dp[end] = max(dp[end], dp[start] + end - start + tip)
            for j in range(i + 1, len(rides)):
                if rides[j][0] >= end:
                    dp[rides[j][1]] = max(dp[rides[j][1]], dp[end] + rides[j][1] - rides[j][0] + rides[j][2])
                    break
        return dp[-1]
        

    