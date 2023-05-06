/**https://leetcode.com/problems/count-palindromic-subsequences/ */
//Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since the answer may be very large, return it modulo 109 + 7.
//Note:
//A string is palindromic if it reads the same forward and backward.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.


/**
 * @param {string} s
 * @return {number}
 */
var countPalindromes = function(s) {
    let mod = 1000000007;
    let n = s.length;
    let dp = new Array(n);
    for(let i = 0; i < n; i++){
        dp[i] = new Array(n).fill(0);
    }
    for(let i = 0; i < n; i++){
        dp[i][i] = 1;
    }
    for(let i = 0; i < n - 1; i++){
        dp[i][i + 1] = 2;
    }
    for(let len = 3; len <= n; len++){
        for(let i = 0; i < n - len + 1; i++){
            let j = i + len - 1;
            if(s[i] == s[j]){
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % mod;
            }else{
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + mod) % mod;
            }
        }
    }
    return dp[0][n - 1];
    
};

    