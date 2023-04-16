/**https://leetcode.com/problems/swim-in-rising-water/ */
//You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
//The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
//Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).


/**
 * @param {number[][]} grid
 * @return {number}
 */
var swimInWater = function(grid) {
    let n = grid.length;
    let dp = [];
    for(let i = 0; i < n; i++){
        dp.push([]);
        for(let j = 0; j < n; j++){
            dp[i].push(0);
        }
    }
    dp[0][0] = 1;
    for(let i = 1; i < n; i++){
        if(grid[i][0] >= grid[i - 1][0]){
            dp[i][0] = dp[i - 1][0];
        }
        if(grid[0][i] >= grid[0][i - 1]){
            dp[0][i] = dp[0][i - 1];
        }
    }
    for(let i = 1; i < n; i++){
        for(let j = 1; j < n; j++){
            if(grid[i][j] >= grid[i - 1][j] && grid[i][j] >= grid[i][j - 1]){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }else if(grid[i][j] >= grid[i - 1][j]){
                dp[i][j] = dp[i - 1][j];
            }else if(grid[i][j] >= grid[i][j - 1]){
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[n - 1][n - 1];
    
};

    