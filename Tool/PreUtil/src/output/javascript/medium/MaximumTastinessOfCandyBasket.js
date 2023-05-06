/**https://leetcode.com/problems/maximum-tastiness-of-candy-basket/ */
//You are given an array of positive integers price where price[i] denotes the price of the ith candy and a positive integer k.
//The store sells baskets of k distinct candies. The tastiness of a candy basket is the smallest absolute difference of the prices of any two candies in the basket.
//Return the maximum tastiness of a candy basket.


/**
 * @param {number[]} price
 * @param {number} k
 * @return {number}
 */
var maximumTastiness = function(price, k) {
    let n = price.length;
    let dp = new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(0));
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= k; j++){
            if(j > i){
                dp[i][j] = dp[i][j - 1];
            }else{
                dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - 1] + price[i - 1]);
            }
        }
    }
    return dp[n][k];
    
};

    