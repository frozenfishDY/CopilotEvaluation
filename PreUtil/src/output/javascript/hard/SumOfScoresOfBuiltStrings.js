/**https://leetcode.com/problems/sum-of-scores-of-built-strings/ */
//You are building a string s of length n one character at a time, prepending each new character to the front of the string. The strings are labeled from 1 to n, where the string with length i is labeled si.
//For example, for s = "abaca", s1 == "a", s2 == "ca", s3 == "aca", etc.
//The score of si is the length of the longest common prefix between si and sn (Note that s == sn).
//Given the final string s, return the sum of the score of every si.


/**
 * @param {string} s
 * @return {number}
 */
var sumScores = function(s) {
    let n = s.length;
    let dp = new Array(n + 1);
    for(let i = 0; i <= n; i++){
        dp[i] = new Array(n + 1).fill(0);
    }
    let ans = 0;
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            if(s[i - 1] == s[n - j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = 0;
            }
            ans += dp[i][j];
        }
    }
    return ans;
    
};

    