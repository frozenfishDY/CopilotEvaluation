/**https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/ */
//Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
//It is guaranteed that there will be a rectangle with a sum no larger than k.


/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var maxSumSubmatrix = function(matrix, k) {
    let m = matrix.length;
    let n = matrix[0].length;
    let result = -Infinity;
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            let dp = [];
            for(let a = 0; a <= m; a++){
                dp.push([]);
                for(let b = 0; b <= n; b++){
                    dp[a].push(0);
                }
            }
            for(let a = 1; a <= m; a++){
                for(let b = 1; b <= n; b++){
                    dp[a][b] = dp[a - 1][b] + dp[a][b - 1] - dp[a - 1][b - 1] + matrix[a - 1][b - 1];
                }
            }
            for(let a = i; a <= m; a++){
                for(let b = j; b <= n; b++){
                    let sum = dp[a][b] - dp[a - i][b] - dp[a][b - j] + dp[a - i][b - j];
                    if(sum <= k){
                        result = Math.max(result, sum);
                    }
                }
            }
        }
    }
    return result;
    
};

    