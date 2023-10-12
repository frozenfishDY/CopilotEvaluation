/**https://leetcode.com/problems/palindromic-substrings/ */
//Given a string s, return the number of palindromic substrings in it.
//A string is a palindrome when it reads the same backward as forward.
//A substring is a contiguous sequence of characters within the string.
// 
//Example 1:
//Input: s = "abc"
//Output: 3
//Explanation: Three palindromic strings: "a", "b", "c".
//Example 2:
//Input: s = "aaa"
//Output: 6
//Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int result = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= n - 1; j++) {
                if (i > j) {
                    dp[i][j] = false;
                } else if (i == j) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = (s.charAt(i) == s.charAt(j)) && (i + 1 == j || dp[i + 1][j - 1]);
                }
                if (dp[i][j]) {
                    result++;
                }
            }
        }
        return result;
    }
}