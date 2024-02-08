/**https://leetcode.com/problems/dungeon-game/ */
//The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
//The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
//Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
//To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
//Return the knight's minimum initial health so that he can rescue the princess.
//Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.


/**
 * @param {number[][]} dungeon
 * @return {number}
 */
var calculateMinimumHP = function(dungeon) {
    let m = dungeon.length;
    let n = dungeon[0].length;
    let dp = [];
    for(let i = 0; i <= m; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(Number.MAX_SAFE_INTEGER);
        }
    }
    dp[m][n - 1] = 1;
    dp[m - 1][n] = 1;
    for(let i = m - 1; i >= 0; i--){
        for(let j = n - 1; j >= 0; j--){
            let min = Math.min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = Math.max(min - dungeon[i][j], 1);
        }
    }
    return dp[0][0];
    
};

    