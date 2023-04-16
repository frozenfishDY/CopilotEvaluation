/**https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/ */
//You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.
//The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).
//Find the kth largest value (1-indexed) of all the coordinates of matrix.


/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthLargestValue = function(matrix, k) {
    let m = matrix.length;
    let n = matrix[0].length;
    let dp = new Array(m);
    for (let i = 0; i < m; i++) {
        dp[i] = new Array(n).fill(0);
    }
    let res = [];
    dp[0][0] = matrix[0][0];
    res.push(dp[0][0]);
    for (let i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] ^ matrix[i][0];
        res.push(dp[i][0]);
    }
    for (let j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] ^ matrix[0][j];
        res.push(dp[0][j]);
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i][j];
            res.push(dp[i][j]);
        }
    }
    res.sort((a, b) => b - a);
    return res[k - 1];
    
};

    