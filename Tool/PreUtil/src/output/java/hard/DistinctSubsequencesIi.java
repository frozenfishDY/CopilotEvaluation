/**https://leetcode.com/problems/distinct-subsequences-ii/ */
//Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.


class DistinctSubsequencesIi {
    public int distinctSubseqII(String s) {
        int n = s.length();
        int mod = 1000000007;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        int[] last = new int[26];
        Arrays.fill(last, -1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] * 2 % mod;
            int c = s.charAt(i - 1) - 'a';
            if (last[c] >= 0) {
                dp[i] -= dp[last[c]];
            }
            dp[i] %= mod;
            last[c] = i - 1;
        }
        dp[n]--;
        if (dp[n] < 0) {
            dp[n] += mod;
        }
        return dp[n];
        
    }
}
     
    