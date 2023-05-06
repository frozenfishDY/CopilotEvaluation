/**https://leetcode.com/problems/distinct-echo-substrings/ */
//Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).


class DistinctEchoSubstrings {
    public int distinctEchoSubstrings(String text) {
        int n = text.length();
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (text.charAt(i - 1) == text.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
        Set<String> set = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (dp[i][j] > 0 && dp[i][j] == j - i) {
                    set.add(text.substring(i - 1, j - 1));
                }
            }
        }
        return set.size();
        
    }
}
     
    