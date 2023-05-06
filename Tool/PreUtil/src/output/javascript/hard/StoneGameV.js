/**https://leetcode.com/problems/stone-game-v/ */
//There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.
//In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.
//The game ends when there is only one stone remaining. Alice's is initially zero.
//Return the maximum score that Alice can obtain.


/**
 * @param {number[]} stoneValue
 * @return {number}
 */
var stoneGameV = function(stoneValue) {
    let n = stoneValue.length;
    let pre = new Array(n + 1).fill(0);
    for(let i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + stoneValue[i - 1];
    }
    let dp = new Array(n + 1);
    for(let i = 0; i <= n; i++){
        dp[i] = new Array(n + 1).fill(0);
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][j - 1] + (distance(stoneValue[i - 1], stoneValue[j - 1]) <= r * r ? 1 : 0);
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

    