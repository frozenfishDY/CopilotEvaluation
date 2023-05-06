/**https://leetcode.com/problems/palindrome-partitioning-iv/ */
//Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.
//A string is said to be palindrome if it the same string when reversed.


/**
 * @param {string} s
 * @return {boolean}
 */
var checkPartitioning = function(s) {
    let n = s.length;
    let dp = new Array(n);
    for(let i = 0; i < n; i++){
        dp[i] = new Array(n);
    }
    for(let i = 0; i < n; i++){
        dp[i][i] = true;
    }
    for(let i = 0; i < n - 1; i++){
        dp[i][i + 1] = s[i] == s[i + 1];
    }
    for(let len = 3; len <= n; len++){
        for(let i = 0; i + len - 1 < n; i++){
            let j = i + len - 1;
            dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
        }
    }
    for(let i = 0; i < n - 2; i++){
        if(dp[0][i]){
            for(let j = i + 1; j < n - 1; j++){
                if(dp[i + 1][j] && dp[j + 1][n - 1]){
                    return true;
                }
            }
        }
    }
    return false;
    
};

    