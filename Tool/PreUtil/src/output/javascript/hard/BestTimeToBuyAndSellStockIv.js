/**https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/ */
//You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
//Find the maximum profit you can achieve. You may complete at most k transactions.
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(k, prices) {
    let n = prices.length;
    if(k >= n / 2){
        let result = 0;
        for(let i = 1; i < n; i++){
            result += Math.max(0, prices[i] - prices[i - 1]);
        }
        return result;
    }
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= k; j++){
            dp[i].push([]);
            for(let l = 0; l <= 1; l++){
                dp[i][j].push(0);
            }
        }
    }
    for(let i = 0; i <= n; i++){
        for(let j = 0; j <= k; j++){
            dp[i][j][0] = 0;
            dp[i][j][1] = -Infinity;
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= k; j++){
            dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
            dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
        }
    }
    return dp[n][k][0];
    
};

    