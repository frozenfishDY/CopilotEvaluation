/**https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/ */
//Given a string s. In one step you can insert any character at any index of the string.
//Return the minimum number of steps to make s palindrome.
//A Palindrome String is one that reads the same backward as well as forward.


/**
 * @param {string} s
 * @return {number}
 */
var minInsertions = function(s) {
    let n = s.length;
    let dp = new Array(n);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(n).fill(0);
    }
    for(let i = 0; i < n; i++){
        dp[i][i] = 0;
    }
    for(let i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            dp[i][i + 1] = 0;
        }else{
            dp[i][i + 1] = 1;
        }
    }
    for(let i = 2; i < n; i++){
        for(let j = 0; j < n - i; j++){
            if(s[j] == s[j + i]){
                dp[j][j + i] = dp[j + 1][j + i - 1];
            }else{
                dp[j][j + i] = Math.min(dp[j + 1][j + i], dp[j][j + i - 1]) + 1;
            }
        }
    }
    return dp[0][n - 1];
    
};

    