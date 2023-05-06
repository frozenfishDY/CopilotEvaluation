/**https://leetcode.com/problems/rearranging-fruits/ */
//You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:
//Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
//The cost of the swap is min(basket1[i],basket2[j]).
//Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.
//Return the minimum cost to make both the baskets equal or -1 if impossible.


class RearrangingFruits {
    public long minCost(int[] basket1, int[] basket2) {
        int n = basket1.length;
        long[][] dp = new long[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], Long.MAX_VALUE);
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == Long.MAX_VALUE) {
                    continue;
                }
                if (i < n - 1) {
                    dp[i + 1][j] = Math.min(dp[i + 1][j], dp[i][j] + basket1[i]);
                }
                if (j < n - 1) {
                    dp[i][j + 1] = Math.min(dp[i][j + 1], dp[i][j] + basket2[j]);
                }
                if (i < n - 1 && j < n - 1) {
                    dp[i + 1][j + 1] = Math.min(dp[i + 1][j + 1], dp[i][j] + Math.min(basket1[i], basket2[j]));
                }
            }
        }
        return dp[n - 1][n - 1] == Long.MAX_VALUE ? -1 : dp[n - 1][n - 1];
        
    }
}
     
    