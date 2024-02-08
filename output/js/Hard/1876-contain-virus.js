/**https://leetcode.com/problems/contain-virus/ */
//A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.
//The world is modeled as an m x n binary grid isInfected, where isInfected[i][j] == 0 represents uninfected cells, and isInfected[i][j] == 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.
//Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There will never be a tie.
//Return the number of walls used to quarantine all the infected regions. If the world will become fully infected, return the number of walls used.


/**
 * @param {number[][]} isInfected
 * @return {number}
 */
var containVirus = function(isInfected) {
    let m = isInfected.length;
    let n = isInfected[0].length;
    let dp = [];
    for(let i = 0; i <= m; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push([]);
            for(let k = 0; k <= m; k++){
                dp[i][j].push([]);
                for(let l = 0; l <= n; l++){
                    dp[i][j][k].push(0);
                }
            }
        }
    }
    for(let i = 0; i <= m; i++){
        dp[i][i][i][i] = 1;
    }
    for(let i = 1; i <= m; i++){
        for(let j = i - 1; j >= 0; j--){
            if(s[i - 1] === s[j]){
                dp[i][j][i][j] = dp[i - 1][j][i - 1][j];
            }else{
                dp[i][j][i][j] = Math.min(dp[i - 1][j][i - 1][j], dp[i][j + 1][i][j + 1]) + 1;
            }
        }
    }
    return dp[m][0][m][0];
    
};

    