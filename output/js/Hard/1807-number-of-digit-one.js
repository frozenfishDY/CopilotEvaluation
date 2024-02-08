/**https://leetcode.com/problems/number-of-digit-one/ */
//Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.


/**
 * @param {number} n
 * @return {number}
 */
var countDigitOne = function(n) {
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= 9; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= 9; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n][9];
    
};

    