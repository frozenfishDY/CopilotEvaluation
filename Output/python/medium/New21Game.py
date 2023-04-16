#https://leetcode.com/problems/new-21-game/
#Alice plays the following game, loosely based on the card game "21".
#Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.
#Alice stops drawing numbers when she gets k or more points.
#Return the probability that Alice has n or fewer points.
#Answers within 10-5 of the actual answer are considered accepted.


class Solution(object):
    def new21Game(self, n, k, maxPts):
        """
        :type n: int
        :type k: int
        :type maxPts: int
        :rtype: float
        """
        if k == 0:
            return 1.0
        dp = [0.0] * (k + maxPts)
        for i in range(k, k + maxPts):
            dp[i] = 1.0 if i <= n else 0.0
        dp[k - 1] = 1.0 * min(n - k + 1, maxPts) / maxPts
        for i in range(k - 2, -1, -1):
            dp[i] = dp[i + 1] - (dp[i + maxPts + 1] - dp[i + 1]) / maxPts
        return dp[0]
        

    