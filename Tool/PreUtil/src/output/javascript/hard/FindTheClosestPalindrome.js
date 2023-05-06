/**https://leetcode.com/problems/find-the-closest-palindrome/ */
//Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
//The closest is defined as the absolute difference minimized between two integers.


/**
 * @param {string} n
 * @return {string}
 */
var nearestPalindromic = function(n) {
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            if(i > j){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= n; i++){
        ans.push(dp[n][i] - dp[n][i - 1]);
    }
    return ans;
    
};

    