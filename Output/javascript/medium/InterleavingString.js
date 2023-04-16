/**https://leetcode.com/problems/interleaving-string/ */
//Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
//An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
//s = s1 + s2 + ... + sn
//t = t1 + t2 + ... + tm
//|n - m| <= 1
//The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
//Note: a + b is the concatenation of strings a and b.


/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} s3
 * @return {boolean}
 */
var isInterleave = function(s1, s2, s3) {
    let m = s1.length;
    let n = s2.length;
    let k = s3.length;
    if(m + n != k){
        return false;
    }
    let dp = new Array(m + 1);
    for(let i = 0; i <= m; i++){
        dp[i] = new Array(n + 1);
    }
    dp[0][0] = true;
    for(let i = 1; i <= m; i++){
        dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    }
    for(let i = 1; i <= n; i++){
        dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
    }
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    return dp[m][n];
    
};

    