/**https://leetcode.com/problems/ones-and-zeroes/ */
//You are given an array of binary strings strs and two integers m and n.
//Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
//A set x is a subset of a set y if all elements of x are also elements of y.


/**
 * @param {string[]} strs
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var findMaxForm = function(strs, m, n) {
    let dp = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for(let str of strs){
        let [zero, one] = getZeroOne(str);
        for(let i = m; i >= zero; i--){
            for(let j = n; j >= one; j--){
                dp[i][j] = Math.max(dp[i][j], dp[i - zero][j - one] + 1);
            }
        }
    }
    return dp[m][n];
    
    
    
};

    