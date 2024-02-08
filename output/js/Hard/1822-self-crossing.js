/**https://leetcode.com/problems/self-crossing/ */
//You are given an array of integers distance.
//You start at the point (0, 0) on an X-Y plane, and you move distance[0] meters to the north, then distance[1] meters to the west, distance[2] meters to the south, distance[3] meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.
//Return true if your path crosses itself or false if it does not.


/**
 * @param {number[]} distance
 * @return {boolean}
 */
var isSelfCrossing = function(distance) {
    let n = distance.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= 3; j++){
            dp[i].push([]);
            for(let k = 0; k <= 3; k++){
                dp[i][j].push(false);
            }
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= 3; j++){
            for(let k = 1; k <= 3; k++){
                if(i - j >= 0 && k === 1 && dp[i - j][k][3]){
                    dp[i][j][k] = true;
                }
                else if(i - j >= 0 && k === 2 && dp[i - j][k][1]){
                    dp[i][j][k] = true;
                }
                else if(i - j >= 0 && k === 3 && dp[i - j][k][2]){
                    dp[i][j][k] = true;
                }
                else if(i - j >= 0 && k === 1 && dp[i - j][k][2] && distance[i - 1] >= distance[i - j - 1]){
                    dp[i][j][k] = true;
                }
                else if(i - j >= 0 && k === 2 && dp[i - j][k][3] && distance[i - 1] >= distance[i - j - 1]){
                    dp[i][j][k] = true;
                }
                else if(i - j >= 0 && k === 3 && dp[i - j][k][1] && distance[i - 1] >= distance[i - j - 1]){
                    dp[i][j][k] = true;
                }
                else if(i - j >= 0 && k === 1 && dp[i - j][k][1] && distance[i - 1] >= distance[i - j - 1] && dp[i - j][k][2] && distance[i - 1] >= distance[i - j - 1]){
                    dp[i][j][k] = true;
                }
                else if(i - j >= 0 && k === 2 && dp[i - j][k][2] && distance [i - 1] >= distance[i - j - 1] && dp[i - j][k][3] && distance[i - 1] >= distance[i - j - 1]){
                    dp[i][j][k] = true;
                }
                else if(i - j >= 0 && k === 3 && dp[i - j][k][3] && distance[i - 1] >= distance[i - j - 1] && dp[i - j][k][1] && distance[i - 1] >= distance[i - j - 1]){

                    dp[i][j][k] = true;
                }
                else{
                    dp[i][j][k] = dp[i - 1][j][k];
                }

            }
        }
    }
    return dp[n][3][3];
    
};

    