/**https://leetcode.com/problems/unique-paths-ii/ */
//You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
//An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
//Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
//The testcases are generated so that the answer will be less than or equal to 2 * 10^9.


/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    let result = 0;
    let m = obstacleGrid.length;
    let n = obstacleGrid[0].length;
    let dp = new Array(m);
    for(let i = 0; i < m; i++){
        dp[i] = new Array(n);
    }
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(obstacleGrid[i][j] == 1){
                dp[i][j] = 0;
            }else if(i == 0 && j == 0){
                dp[i][j] = 1;
            }else if(i == 0){
                dp[i][j] = dp[i][j - 1];
            }else if(j == 0){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
    
};

    