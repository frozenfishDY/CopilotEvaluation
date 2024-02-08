/**https://leetcode.com/problems/count-different-palindromic-subsequences/ */
//Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of a string is obtained by deleting zero or more characters from the string.
//A sequence is palindromic if it is equal to the sequence reversed.
//Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.


class CountDifferentPalindromicSubsequences {
    public int countPalindromicSubsequences(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j + i < n; j++) {
                if (s.charAt(j) == s.charAt(j + i)) {
                    int left = j + 1;
                    int right = j + i - 1;
                    while (left <= right && s.charAt(left) != s.charAt(j)) {
                        left++;
                    }
                    while (left <= right && s.charAt(right) != s.charAt(j)) {
                        right--;
                    }
                    if (left > right) {
                        dp[j][j + i] = dp[j + 1][j + i - 1] * 2 + 2;
                    } else if (left == right) {
                        dp[j][j + i] = dp[j + 1][j + i - 1] * 2 + 1;
                    } else {
                        dp[j][j + i] = dp[j + 1][j + i - 1] * 2 - dp[left + 1][right - 1];
                    }
                } else {
                    dp[j][j + i] = dp[j + 1][j + i] + dp[j][j + i - 1] - dp[j + 1][j + i - 1];
                }
                dp[j][j + i] = dp[j][j + i] < 0 ? dp[j][j + i] + 1000000007 : dp[j][j + i] % 1000000007;
            }
        }
        return dp[0][n - 1];
        
    }
}
     
    