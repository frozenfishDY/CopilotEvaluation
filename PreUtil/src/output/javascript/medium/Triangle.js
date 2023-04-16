/**https://leetcode.com/problems/triangle/ */
//Given a triangle array, return the minimum path sum from top to bottom.
//For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.


/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    let dp = new Array(triangle.length).fill(0);
    dp[0] = triangle[0][0];
    for(let i = 1; i < triangle.length; i++){
        dp[i] = dp[i - 1] + triangle[i][i];
        for(let j = i - 1; j > 0; j--){
            dp[j] = Math.min(dp[j - 1], dp[j]) + triangle[i][j];
        }
        dp[0] += triangle[i][0];
    }
    let min = dp[0];
    for(let i = 1; i < dp.length; i++){
        min = Math.min(min, dp[i]);
    }
    return min;
    
};

    