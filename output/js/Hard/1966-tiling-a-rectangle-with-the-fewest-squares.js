/**https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/ */
//Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.


/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var tilingRectangle = function(n, m) {
    let dp = new Array(n + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(m + 1).fill(0);
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= m; j++){
            if(i == j){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = Infinity;
                for(let k = 1; k <= i / 2; k++){
                    dp[i][j] = Math.min(dp[i][j], dp[k][j] + dp[i - k][j]);
                }
                for(let k = 1; k <= j / 2; k++){
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[i][j - k]);
                }
            }
        }
    }
    return dp[n][m];
    
};

    