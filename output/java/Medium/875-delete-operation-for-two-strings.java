/**https://leetcode.com/problems/delete-operation-for-two-strings/ */
//Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
//In one step, you can delete exactly one character in either string.
// 
//Example 1:
//Input: word1 = "sea", word2 = "eat"
//Output: 2
//Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
//Example 2:
//Input: word1 = "leetcode", word2 = "etco"
//Output: 4
// 
//Constraints:
//	1 <= word1.length, word2.length <= 500
//	word1 and word2 consist of only lowercase English letters.
class Solution {
    public int minDistance(String word1, String word2) {
        int[][] dp = new int[word1.length()][word2.length()];
        return word1.length() + word2.length() - 2 * lcs(word1, word2, word1.length() - 1, word2.length() - 1, dp);
    }
    private int lcs(String word1, String word2, int i, int j, int[][] dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] > 0) {
            return dp[i][j];
        }
        if (word1.charAt(i) == word2.charAt(j)) {
            dp[i][j] = 1 + lcs(word1, word2, i - 1, j - 1, dp);
        } else {
            dp[i][j] = Math.max(lcs(word1, word2, i - 1, j, dp), lcs(word1, word2, i, j - 1, dp));
        }
        return dp[i][j];
    }
}