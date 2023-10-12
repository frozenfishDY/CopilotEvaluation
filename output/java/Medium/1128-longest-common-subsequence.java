/**https://leetcode.com/problems/longest-common-subsequence/ */
//Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//	For example, "ace" is a subsequence of "abcde".
//A common subsequence of two strings is a subsequence that is common to both strings.
// 
//Example 1:
//Input: text1 = "abcde", text2 = "ace" 
//Output: 3  
//Explanation: The longest common subsequence is "ace" and its length is 3.
//Example 2:
//Input: text1 = "abc", text2 = "abc"
//Output: 3
//Explanation: The longest common subsequence is "abc" and its length is 3.
//Example 3:
//Input: text1 = "abc", text2 = "def"
//Output: 0
//Explanation: There is no such common subsequence, so the result is 0.
// 
//Constraints:
//	1 <= text1.length, text2.length <= 1000
//	text1 and text2 consist of only lowercase English characters.
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        // 1. create a 2d array to store the longest common subsequence
		// 2. loop through the 2 strings
		// 2.1 if the current character is the same, update the longest common subsequence
		// 2.2 if the current character is not the same, update the longest common subsequence
		// 3. return the last element in the 2d array
        int[][] dp = new int[text1.length()+1][text2.length()+1];
        for(int i = 1; i <= text1.length(); i++) {
            char c1 = text1.charAt(i-1);
            for(int j = 1; j <= text2.length(); j++) {
                char c2 = text2.charAt(j-1);
                if(c1 == c2) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    int left = dp[i][j-1];
                    int up = dp[i-1][j];
                    dp[i][j] = Math.max(left, up);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
}