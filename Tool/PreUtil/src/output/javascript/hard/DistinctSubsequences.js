/**https://leetcode.com/problems/distinct-subsequences/ */
//Given two strings s and t, return the number of distinct subsequences of s which equals t.
//The test cases are generated so that the answer fits on a 32-bit signed integer.


/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
    let m = s.length;
    let n = t.length;
    let dp = [];
    for(let i = 0; i <= m; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= m; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            if(s[i - 1] === t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
    
};

    