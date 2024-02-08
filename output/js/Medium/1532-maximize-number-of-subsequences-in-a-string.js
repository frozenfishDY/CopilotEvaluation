/**https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/ */
//You are given a 0-indexed string text and another 0-indexed string pattern of length 2, both of which consist of only lowercase English letters.
//You can add either pattern[0] or pattern[1] anywhere in text exactly once. Note that the character can be added even at the beginning or at the end of text.
//Return the maximum number of times pattern can occur as a subsequence of the modified text.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.


/**
 * @param {string} text
 * @param {string} pattern
 * @return {number}
 */
var maximumSubsequenceCount = function(text, pattern) {
    let n = text.length;
    let m = pattern.length;
    let dp = new Array(n + 1);
    for (let i = 0; i <= n; i++) {
        dp[i] = new Array(m + 1).fill(0);
    }
    for (let i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            if (text[i - 1] === pattern[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
    
};

    