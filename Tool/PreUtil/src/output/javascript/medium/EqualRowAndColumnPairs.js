/**https://leetcode.com/problems/equal-row-and-column-pairs/ */
//Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
//A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).


/**
 * @param {number[][]} grid
 * @return {number}
 */
var equalPairs = function(grid) {
    let n = grid.length;
    let dp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    let res = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === grid[j][i]) {
                dp[i][j] = 1;
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    dp[i][j] -= dp[i - 1][j - 1];
                }
            }
            res += dp[i][j];
        }
    }
    return res;
    
};

    