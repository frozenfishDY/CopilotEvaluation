/**https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/ */
//Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.
// 
//Example 1:
//Input: s1 = "sea", s2 = "eat"
//Output: 231
//Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
//Deleting "t" from "eat" adds 116 to the sum.
//At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
//Example 2:
//Input: s1 = "delete", s2 = "leet"
//Output: 403
//Explanation: Deleting "dee" from "delete" to turn the string into "let",
//adds 100[d] + 101[e] + 101[e] to the sum.
//Deleting "e" from "leet" adds 101[e] to the sum.
//At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
//If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
// 
//Constraints:
//	1 <= s1.length, s2.length <= 1000
//	s1 and s2 consist of lowercase English letters.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var minimumDeleteSum = function(s1, s2) {
    const dp = new Array(s1.length + 1).fill(0).map(() => new Array(s2.length + 1).fill(0));
    for (let i = 1; i <= s1.length; i++) {
        dp[i][0] = dp[i - 1][0] + s1.charCodeAt(i - 1);
    }
    for (let j = 1; j <= s2.length; j++) {
        dp[0][j] = dp[0][j - 1] + s2.charCodeAt(j - 1);
    }
    for (let i = 1; i <= s1.length; i++) {
        for (let j =1; j <= s2.length; j++) {
            if (s1[i - 1] === s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                const deleteS1 = dp[i - 1][j] + s1.charCodeAt(i - 1);
                const deleteS2 = dp[i][j - 1] + s2.charCodeAt(j - 1);
                dp[i][j] = Math.min(deleteS1, deleteS2);
            }
        }
    }
    return dp[s1.length][s2.length];
};