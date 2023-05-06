/**https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/ */
//Given a string s. In one step you can insert any character at any index of the string.
//Return the minimum number of steps to make s palindrome.
//A Palindrome String is one that reads the same backward as well as forward.


class MinimumInsertionStepsToMakeAStringPalindrome {
    public int minInsertions(String s) {
        int n = s.length();
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s.charAt(i - 1) == s.charAt(n - j)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n - dp[n][n];
        
    }
}
     
    