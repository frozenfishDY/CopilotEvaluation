/**https://leetcode.com/problems/palindrome-partitioning-iii/ */
//You are given a string s containing lowercase letters and an integer k. You need to :
//First, change some characters of s to other lowercase English letters.
//Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
//Return the minimal number of characters that you need to change to divide the string.


class PalindromePartitioningIii {
    public int palindromePartition(String s, int k) {
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = s.charAt(i) == s.charAt(i + 1) ? 0 : 1;
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j - 1] + (s.charAt(i) == s.charAt(j) ? 0 : 1);
            }
        }
        int[][] dp2 = new int[n][k];
        for (int i = 0; i < n; i++) {
            dp2[i][0] = dp[0][i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < k; j++) {
                dp2[i][j] = Integer.MAX_VALUE;
                for (int l = 0; l < i; l++) {
                    dp2[i][j] = Math.min(dp2[i][j], dp2[l][j - 1] + dp[l + 1][i]);
                }
            }
        }
        return dp2[n - 1][k - 1];
        
    }
}
     
    