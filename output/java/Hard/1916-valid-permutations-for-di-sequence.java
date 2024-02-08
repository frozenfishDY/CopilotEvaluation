/**https://leetcode.com/problems/valid-permutations-for-di-sequence/ */
//You are given a string s of length n where s[i] is either:
//'D' means decreasing, or
//'I' means increasing.
//A permutation perm of n + 1 integers of all the integers in the range [0, n] is called a valid permutation if for all valid i:
//If s[i] == 'D', then perm[i] > perm[i + 1], and
//If s[i] == 'I', then perm[i] < perm[i + 1].
//Return the number of valid permutations perm. Since the answer may be large, return it modulo 109 + 7.


class ValidPermutationsForDiSequence {
    public int numPermsDISequence(String s) {
        int n = s.length();
        int mod = 1000000007;
        int[][] dp = new int[n + 1][n + 1];
        Arrays.fill(dp[0], 1);
        for (int i = 1; i <= n; i++) {
            if (s.charAt(i - 1) == 'D') {
                for (int j = i; j >= 0; j--) {
                    dp[i][j] = j == i ? 0 : (dp[i][j + 1] + dp[i - 1][j]) % mod;
                }
            } else {
                for (int j = 0; j <= i; j++) {
                    dp[i][j] = j == 0 ? 0 : (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
                }
            }
        }
        return dp[n][0];
        
    }
}
     
    