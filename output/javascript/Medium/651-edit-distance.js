/**https://leetcode.com/problems/edit-distance/ */
//Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
//You have the following three operations permitted on a word:
//	Insert a character
//	Delete a character
//	Replace a character
// 
//Example 1:
//Input: word1 = "horse", word2 = "ros"
//Output: 3
//Explanation: 
//horse -> rorse (replace 'h' with 'r')
//rorse -> rose (remove 'r')
//rose -> ros (remove 'e')
//Example 2:
//Input: word1 = "intention", word2 = "execution"
//Output: 5
//Explanation: 
//intention -> inention (remove 't')
//inention -> enention (replace 'i' with 'e')
//enention -> exention (replace 'n' with 'x')
//exention -> exection (replace 'n' with 'c')
//exection -> execution (insert 'u')
// 
//Constraints:
//	0 <= word1.length, word2.length <= 500
//	word1 and word2 consist of lowercase English letters.
/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    //Memory Usage: 42.6 MB, less than 97.14% of JavaScript online submissions for Edit Distance.
    //console.log(word1, word2);
    let len1 = word1.length;
    let len2 = word2.length;
    if (len1 === 0) return len2;
    if (len2 === 0) return len1;
    let dp = new Array(len1 + 1);
    for (let i = 0; i <= len1; i++) {
        dp[i] = new Array(len2 + 1).fill(0);
    }
    for (let i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for (let i = 0; i <= len2; i++) {
        dp[0][i] = i;
    }
    //console.log(dp);
    for (let i = 1; i <= len1; i++) {
        let char1 = word1.charAt(i - 1);
        for (let j = 1; j <= len2; j++) {
            let char2 = word2.charAt(j - 1);
            if (char1 === char2) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                let min = Math.min(dp[i - 1][j], dp[i][j - 1]);
                min = Math.min(min, dp[i - 1][j - 1]);
                dp[i][j] = min + 1;
            }
        }
    }
    //console.log(dp);
    return dp[len1][len2];
};