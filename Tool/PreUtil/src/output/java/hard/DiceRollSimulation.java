/**https://leetcode.com/problems/dice-roll-simulation/ */
//A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.
//Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls. Since the answer may be too large, return it modulo 109 + 7.
//Two sequences are considered different if at least one element differs from each other


class DiceRollSimulation {
    public int dieSimulator(int n, int[] rollMax) {
        int[][] dp = new int[n + 1][6];
        for (int i = 0; i < 6; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 6; k++) {
                    if (j == k) {
                        if (rollMax[j] >= i) {
                            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1000000007;
                        }
                    } else {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1000000007;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            sum = (sum + dp[n][i]) % 1000000007;
        }
        return sum;
        
    }
}
     
    