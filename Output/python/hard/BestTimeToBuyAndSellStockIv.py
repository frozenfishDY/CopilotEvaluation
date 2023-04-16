#https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
#Find the maximum profit you can achieve. You may complete at most k transactions.
#Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        # initialize the first buy
        first_buy = float('inf')
        # initialize the first profit
        first_profit = 0
        # initialize the second buy
        second_buy = float('inf')
        # initialize the second profit
        second_profit = 0
        # iterate over the prices
        for price in prices:
            # set the first buy to the minimum of the first buy and the price
            first_buy = min(first_buy, price)
            # set the first profit to the maximum of the first profit and the price minus the first buy
            first_profit = max(first_profit, price - first_buy)
            # set the second buy to the minimum of the second buy and the price minus the first profit
            second_buy = min(second_buy, price - first_profit)
            # set the second profit to the maximum of the second profit and the price minus the second buy
            second_profit = max(second_profit, price - second_buy)
        # return the second profit
        return second_profit
        
        
    