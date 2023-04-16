/**https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ */
//Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).


/**
 * @param {number[][]} matrix
 * @return {number}
 */
var longestIncreasingPath = function(matrix) {
    let n = matrix.length;
    let m = matrix[0].length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= m; j++){
            dp[i].push(0);
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= m; j++){
            if(matrix[i - 1][j - 1] > matrix[i - 1][j]){
                dp[i][j] = dp[i - 1][j] + 1;
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = 0;
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= m; j++){
            ans = Math.max(ans, dp[i][j]);
        }
    }
    return ans;
    
};

    