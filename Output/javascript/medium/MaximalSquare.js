/**https://leetcode.com/problems/maximal-square/ */
//Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.


/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function(matrix) {
    if(matrix.length == 0 || matrix[0].length == 0){
        return 0;
    }
    let m = matrix.length;
    let n = matrix[0].length;
    let dp = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    let max = 0;
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            if(matrix[i - 1][j - 1] == '1'){
                dp[i][j] = Math.min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
                max = Math.max(max, dp[i][j]);
            }
        }
    }
    return max * max;
    
};

    