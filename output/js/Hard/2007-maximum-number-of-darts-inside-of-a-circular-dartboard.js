/**https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/ */
//Alice is throwing n darts on a very large wall. You are given an array darts where darts[i] = [xi, yi] is the position of the ith dart that Alice threw on the wall.
//Bob knows the positions of the n darts on the wall. He wants to place a dartboard of radius r on the wall so that the maximum number of darts that Alice throws lies on the dartboard.
//Given the integer r, return the maximum number of darts that can lie on the dartboard.


/**
 * @param {number[][]} darts
 * @param {number} r
 * @return {number}
 */
var numPoints = function(darts, r) {
    let n = darts.length;
    let dp = new Array(n + 1);
    for(let i = 0; i <= n; i++){
        dp[i] = new Array(n + 1).fill(0);
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][j - 1] + (distance(darts[i - 1], darts[j - 1]) <= r * r ? 1 : 0);
        }
    }
    let ans = 0;
    for(let i = 0; i <= n; i++){
        for(let j = i + 1; j <= n; j++){
            let cnt = dp[j][j] - dp[i][i] + dp[i][j] - dp[j][i];
            ans = Math.max(ans, cnt);
        }
    }
    return ans;
    

    
};

    