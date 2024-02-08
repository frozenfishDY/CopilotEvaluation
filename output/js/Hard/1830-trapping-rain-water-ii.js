/**https://leetcode.com/problems/trapping-rain-water-ii/ */
//Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.


/**
 * @param {number[][]} heightMap
 * @return {number}
 */
var trapRainWater = function(heightMap) {
    let m = heightMap.length;
    let n = heightMap[0].length;
    let dp = [];
    for(let i = 0; i <= m; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + heightMap[i - 1][j - 1];
        }
    }
    let result = 0;
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            for(let a = 1; a <= m; a++){
                for(let b = 1; b <= n; b++){
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

    