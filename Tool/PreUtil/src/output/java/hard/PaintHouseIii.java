/**https://leetcode.com/problems/paint-house-iii/ */
//There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.
//A neighborhood is a maximal group of continuous houses that are painted with the same color.
//For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].
//Given an array houses, an m x n matrix cost and an integer target where:
//houses[i]: is the color of the house i, and 0 if the house is not painted yet.
//cost[i][j]: is the cost of paint the house i with the color j + 1.
//Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.


class PaintHouseIii {
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        int[][][] dp = new int[m + 1][n + 1][target + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                Arrays.fill(dp[i][j], Integer.MAX_VALUE / 2);
            }
        }
        dp[0][0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= target; k++) {
                    if (houses[i - 1] == 0) {
                        dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][j][k] + cost[i - 1][j - 1]);
                    }
                    for (int p = 1; p <= n; p++) {
                        if (p == j) {
                            dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][p][k] + (houses[i - 1] == 0 ? cost[i - 1][j - 1] : 0));
                        } else {
                            dp[i][j][k] = Math.min(dp[i][j][k], dp[i - 1][p][k - 1] + (houses[i - 1] == 0 ? cost[i - 1][j - 1] : 0));
                        }
                    }
                }
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            res = Math.min(res, dp[m][i][target]);
        }
        return res == Integer.MAX_VALUE / 2 ? -1 : res;
        
    }
}
     
    