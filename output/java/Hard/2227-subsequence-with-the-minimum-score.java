/**https://leetcode.com/problems/subsequence-with-the-minimum-score/ */
//You are given two strings s and t.
//You are allowed to remove any number of characters from the string t.
//The score of the string is 0 if no characters are removed from the string t, otherwise:
//Let left be the minimum index among all removed characters.
//Let right be the maximum index among all removed characters.
//Then the score of the string is right - left + 1.
//Return the minimum possible score to make t a subsequence of s.
//A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).


class SubsequenceWithTheMinimumScore {
    public int minimumScore(String s, String t) {
        int n = s.length();
        int m = t.length();
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int lcs = dp[n][m];
        return m - lcs;
        
    }
}
     
    