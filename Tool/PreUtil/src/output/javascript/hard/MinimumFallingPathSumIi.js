/**https://leetcode.com/problems/minimum-falling-path-sum-ii/ */
//Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
//A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var minFallingPathSum = function(grid) {
    let n = grid.length;
    let dp = new Array(n);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(n).fill(0);
    }
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            dp[0][j] = grid[0][j];
        }
    }
    for(let i = 1; i < n; i++){
        for(let j = 0; j < n; j++){
            let min = Infinity;
            for(let k = 0; k < n; k++){
                if(k != j){
                    min = Math.min(min, dp[i - 1][k]);
                }
            }
            dp[i][j] = min + grid[i][j];
        }
    }
    let ans = Infinity;
    for(let i = 0; i < n; i++){
        ans = Math.min(ans, dp[n - 1][i]);
    }
    return ans;
    
};

    