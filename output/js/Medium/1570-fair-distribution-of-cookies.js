/**https://leetcode.com/problems/fair-distribution-of-cookies/ */
//You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.
//The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.
//Return the minimum unfairness of all distributions.


/**
 * @param {number[]} cookies
 * @param {number} k
 * @return {number}
 */
var distributeCookies = function(cookies, k) {
    cookies.sort((a, b) => a - b);
    let n = cookies.length;
    let dp = new Array(n).fill(0).map(() => new Array(k).fill(Number.MAX_VALUE));
    for (let i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    for (let i = 1; i < k; i++) {
        for (let j = i; j < n; j++) {
            for (let l = i - 1; l < j; l++) {
                dp[j][i] = Math.min(dp[j][i], dp[l][i - 1] + (cookies[j] - cookies[l]) * (cookies[j] - cookies[l]));
            }
        }
    }
    return dp[n - 1][k - 1];
    
};

    