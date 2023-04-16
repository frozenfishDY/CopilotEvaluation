/**https://leetcode.com/problems/painting-a-grid-with-three-different-colors/ */
//You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
//Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.


/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var colorTheGrid = function(m, n) {
    let mod = 1000000007;
    let dp = new Array(m + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(n + 1).fill(0);
    }
    dp[0][0] = 1;
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            dp[i][j] = (dp[i - 1][j - 1] + (dp[i - 1][j] * (i - 1)) % mod) % mod;
        }
    }
    return dp[m][n];
    
};

    