/**https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/ */
//There are n people and 40 types of hats labeled from 1 to 40.
//Given a 2D integer array hats, where hats[i] is a list of all hats preferred by the ith person.
//Return the number of ways that the n people wear different hats to each other.
//Since the answer may be too large, return it modulo 10^9 + 7.


/**
 * @param {number[][]} hats
 * @return {number}
 */
var numberWays = function(hats) {
    let mod = 1000000007;
    let dp = new Array(41).fill(0);
    dp[0] = 1;
    for(let i = 1; i <= 40; i++){
        dp[i] = dp[i - 1] * (2 * i - 1) * (2 * i) % mod;
    }
    return dp[40];
    
};

    