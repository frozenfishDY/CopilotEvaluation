/**https://leetcode.com/problems/check-if-point-is-reachable/ */
//There exists an infinitely large grid. You are currently at point (1, 1), and you need to reach the point (targetX, targetY) using a finite number of steps.
//In one step, you can move from point (x, y) to any one of the following points:
//(x, y - x)
//(x - y, y)
//(2 * x, y)
//(x, 2 * y)
//Given two integers targetX and targetY representing the X-coordinate and Y-coordinate of your final position, return true if you can reach the point from (1, 1) using some number of steps, and false otherwise.


/**
 * @param {number} targetX
 * @param {number} targetY
 * @return {boolean}
 */
var isReachable = function(targetX, targetY) {
    let dp = [];
    for(let i = 0; i <= targetX; i++){
        dp.push([]);
        for(let j = 0; j <= targetY; j++){
            dp[i].push(false);
        }
    }
    dp[1][1] = true;
    for(let i = 1; i <= targetX; i++){
        for(let j = 1; j <= targetY; j++){
            if(dp[i][j]){
                if(i - j > 0){
                    dp[i - j][j] = true;
                }
                if(j - i > 0){
                    dp[i][j - i] = true;
                }
                dp[2 * i][j] = true;
                dp[i][2 * j] = true;
            }
        }
    }
    return dp[targetX][targetY];
    
};

    