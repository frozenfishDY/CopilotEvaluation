/**https://leetcode.com/problems/cherry-pickup/ */
//You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.
//0 means the cell is empty, so you can pass through,
//1 means the cell contains a cherry that you can pick up and pass through, or
//-1 means the cell contains a thorn that blocks your way.
//Return the maximum number of cherries you can collect by following the rules below:
//Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
//After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
//When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
//If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var cherryPickup = function(grid) {
    let n = grid.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push([]);
            for(let k = 0; k <= n; k++){
                dp[i][j].push([]);
                for(let l = 0; l <= n; l++){
                    dp[i][j][k].push(0);
                }
            }
        }
    }
    for(let i = 0; i <= n; i++){
        dp[i][i][i][i] = 1;
    }
    for(let i = 1; i <= n; i++){
        for(let j = i - 1; j >= 0; j--){
            if(s[i - 1] === s[j]){
                dp[i][j][i][j] = dp[i - 1][j][i - 1][j];
            }else{
                dp[i][j][i][j] = Math.min(dp[i - 1][j][i - 1][j], dp[i][j + 1][i][j + 1]) + 1;
            }
        }
    }
    return dp[n][0][n][0];
    
};

    