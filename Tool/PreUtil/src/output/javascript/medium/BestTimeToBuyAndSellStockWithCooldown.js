/**https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/ */
//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
//After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let n = prices.length;
    let buy = new Array(n);
    let sell = new Array(n);
    let cooldown = new Array(n);
    buy[0] = -prices[0];
    sell[0] = 0;
    cooldown[0] = 0;
    for(let i = 1; i < n; i++){
        buy[i] = Math.max(buy[i - 1], cooldown[i - 1] - prices[i]);
        sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);
        cooldown[i] = Math.max(cooldown[i - 1], sell[i - 1]);
    }
    return sell[n - 1];
    
};

    