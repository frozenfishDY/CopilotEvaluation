/**https://leetcode.com/problems/super-egg-drop/ */
//You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
//You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
//Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
//Return the minimum number of moves that you need to determine with certainty what the value of f is.


/**
 * @param {number} k
 * @param {number} n
 * @return {number}
 */
var superEggDrop = function(k, n) {
    let dp = [];
    for(let i = 0; i <= k; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    let m = 0;
    while(dp[k][m] < n){
        m++;
        for(let i = 1; i <= k; i++){
            dp[i][m] = dp[i][m - 1] + dp[i - 1][m - 1] + 1;
        }
    }
    return m;
    
};

    