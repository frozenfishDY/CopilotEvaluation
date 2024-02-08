/**https://leetcode.com/problems/k-similar-strings/ */
//Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.
//Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.


class KSimilarStrings {
    public int kSimilarity(String s1, String s2) {
        int n = s1.length();
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = s1.charAt(i) == s2.charAt(j) ? 0 : 1;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == n - 1 && j == n - 1) {
                    continue;
                }
                if (i == n - 1) {
                    dp[i][j] += dp[i][j + 1];
                } else if (j == n - 1) {
                    dp[i][j] += dp[i + 1][j];
                } else {
                    dp[i][j] += Math.min(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
        
    }
}
     
    