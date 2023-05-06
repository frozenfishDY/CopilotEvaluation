/**https://leetcode.com/problems/find-all-good-strings/ */
//Given the strings s1 and s2 of size n and the string evil, return the number of good strings.
//A good string has size n, it is alphabetically greater than or equal to s1, it is alphabetically smaller than or equal to s2, and it does not contain the string evil as a substring. Since the answer can be a huge number, return this modulo 10^9 + 7.


/**
 * @param {number} n
 * @param {string} s1
 * @param {string} s2
 * @param {string} evil
 * @return {number}
 */
var findGoodStrings = function(n, s1, s2, evil) {
    let mod = 1000000007;
    let dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    for(let i = 1; i <= n; i++){
        dp[i] = dp[i - 1] * (2 * i - 1) * (2 * i) % mod;
    }
    return dp[n];
    
};

    