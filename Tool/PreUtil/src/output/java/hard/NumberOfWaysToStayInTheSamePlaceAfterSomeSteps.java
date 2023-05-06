/**https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/ */
//You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).
//Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 10^9 + 7.


class NumberOfWaysToStayInTheSamePlaceAfterSomeSteps {
    public int numWays(int steps, int arrLen) {
        int[][] dp = new int[steps + 1][arrLen];
        for (int i = 0; i < arrLen; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= steps; i++) {
            for (int j = 0; j < arrLen; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000007;
                }
                if (j < arrLen - 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % 1000000007;
                }
            }
        }
        return dp[steps][0];

        
    }
}
     
    