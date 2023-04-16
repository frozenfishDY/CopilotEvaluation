/**https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/ */
//There are n uniquely-sized sticks whose lengths are integers from 1 to n. You want to arrange the sticks such that exactly k sticks are visible from the left. A stick is visible from the left if there are no longer sticks to the left of it.
//For example, if the sticks are arranged [1,3,2,5,4], then the sticks with lengths 1, 3, and 5 are visible from the left.
//Given n and k, return the number of such arrangements. Since the answer may be large, return it modulo 10^9 + 7.


/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var rearrangeSticks = function(n, k) {
    let mod = 1000000007;
    let dp = new Array(n + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(k + 1).fill(0);
    }
    dp[0][0] = 1;
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= k; j++){
            dp[i][j] = (dp[i - 1][j - 1] + (dp[i - 1][j] * (i - 1)) % mod) % mod;
        }
    }
    return dp[n][k];
    
};

    