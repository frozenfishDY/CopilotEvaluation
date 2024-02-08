/**https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/ */
//You are given a 2D integer array grid of size m x n, where each cell contains a positive integer.
//A cornered path is defined as a set of adjacent cells with at most one turn. More specifically, the path should exclusively move either horizontally or vertically up to the turn (if there is one), without returning to a previously visited cell. After the turn, the path will then move exclusively in the alternate direction: move vertically if it moved horizontally, and vice versa, also without returning to a previously visited cell.
//The product of a path is defined as the product of all the values in the path.
//Return the maximum number of trailing zeros in the product of a cornered path found in grid.
//Note:
//Horizontal movement means moving in either the left or right direction.
//Vertical movement means moving in either the up or down direction.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxTrailingZeros = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let dp = new Array(m).fill(0).map(() => new Array(n).fill(0));
    let result = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            let count = 0;
            let num = grid[i][j];
            while (num % 5 == 0) {
                count++;
                num /= 5;
            }
            if (i > 0 && j > 0) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + count;
            } else if (i > 0) {
                dp[i][j] = dp[i - 1][j] + count;
            } else if (j > 0) {
                dp[i][j] = dp[i][j - 1] + count;
            } else {
                dp[i][j] = count;
            }
            result = Math.max(result, dp[i][j]);
        }
    }
    return result;
    
};

    