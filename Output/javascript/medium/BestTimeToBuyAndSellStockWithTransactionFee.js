/**https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/ */
//You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
//Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


/**
 * @param {number[]} prices
 * @param {number} fee
 * @return {number}
 */
var maxProfit = function(prices, fee) {
    let n = prices.length;
    let dp = new Array(n).fill(0);
    let min = prices[0];
    for(let i = 1; i < n; i++){
        dp[i] = Math.max(dp[i - 1], prices[i] - min - fee);
        min = Math.min(min, prices[i] - dp[i - 1]);
    }
    return dp[n - 1];
    
};

    