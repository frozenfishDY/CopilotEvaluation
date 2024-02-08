/**https://leetcode.com/problems/cherry-pickup-ii/ */
//You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.
//You have two robots that can collect cherries for you:
//Robot #1 is located at the top-left corner (0, 0), and
//Robot #2 is located at the top-right corner (0, cols - 1).
//Return the maximum number of cherries collection using both robots by following the rules below:
//From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
//When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
//When both robots stay in the same cell, only one takes the cherries.
//Both robots cannot move outside of the grid at any moment.
//Both robots should reach the bottom row in grid.


class CherryPickupIi {
    public int cherryPickup(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] dp = new int[m][n][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    for (int j1 = j - 1; j1 <= j + 1; j1++) {
                        for (int k1 = k - 1; k1 <= k + 1; k1++) {
                            if (j1 >= 0 && j1 < n && k1 >= 0 && k1 < n) {
                                dp[i][j][k] = Math.max(dp[i][j][k], dp[i - 1][j1][k1]);
                            }
                        }
                    }
                    if (dp[i][j][k] >= 0) {
                        dp[i][j][k] += grid[i][j] + (j == k ? 0 : grid[i][k]);
                    }
                }
            }
        }
        int res = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res = Math.max(res, dp[m - 1][j][k]);
            }
        }
        return res;
        
    }
}
     
    