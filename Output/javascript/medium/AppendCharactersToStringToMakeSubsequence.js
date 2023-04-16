/**https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/ */
//You are given two strings s and t consisting of only lowercase English letters.
//Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.


/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var appendCharacters = function(s, t) {
    let m = s.length;
    let n = t.length;
    let dp = new Array(m + 1).fill(0);
    for(let i = 1; i <= m; i++){
        dp[i] = new Array(n + 1).fill(0);
    }
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return n - dp[m][n];
    
};

    