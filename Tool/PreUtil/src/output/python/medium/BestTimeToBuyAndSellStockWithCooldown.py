#https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#You are given an array prices where prices[i] is the price of a given stock on the ith day.
#Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
#After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
#Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        dp = [[0 for i in range(2)] for j in range(len(prices))]
        dp[0][0] = 0
        dp[0][1] = -prices[0]
        for i in range(1, len(prices)):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            if i == 1:
                dp[i][1] = max(dp[i-1][1], -prices[i])
            else:
                dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
        return dp[len(prices)-1][0]
        

    