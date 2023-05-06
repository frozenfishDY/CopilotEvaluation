/**https://leetcode.com/problems/string-compression-ii/ */
//Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".
//Notice that in this problem, we are not adding '1' after single characters.
//Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.
//Find the minimum length of the run-length encoded version of s after deleting at most k characters.


/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLengthOfOptimalCompression = function(s, k) {
    let n = s.length;
    let dp = new Array(n);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(n).fill(0);
    }
    for(let i = 0; i < n; i++){
        dp[i][i] = 1;
    }
    for(let i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            dp[i][i + 1] = 1;
        }else{
            dp[i][i + 1] = 2;
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

    