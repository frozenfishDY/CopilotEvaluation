/**https://leetcode.com/problems/count-vowels-permutation/ */
//Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
//Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
//Each vowel 'a' may only be followed by an 'e'.
//Each vowel 'e' may only be followed by an 'a' or an 'i'.
//Each vowel 'i' may not be followed by another 'i'.
//Each vowel 'o' may only be followed by an 'i' or a 'u'.
//Each vowel 'u' may only be followed by an 'a'.
//Since the answer may be too large, return it modulo 10^9 + 7.


/**
 * @param {number} n
 * @return {number}
 */
var countVowelPermutation = function(n) {
    let dp = new Array(n + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(5).fill(0);
    }
    for(let i = 0; i < 5; i++){
        dp[1][i] = 1;
    }
    for(let i = 2; i <= n; i++){
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % 1000000007;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 1000000007;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % 1000000007;
        dp[i][3] = (dp[i - 1][2]) % 1000000007;
        dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000007;
    }
    let ans = 0;
    for(let i = 0; i < 5; i++){
        ans = (ans + dp[n][i]) % 1000000007;
    }
    return ans;
    
};

    