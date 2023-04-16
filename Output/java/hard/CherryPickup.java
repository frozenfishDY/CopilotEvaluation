/**https://leetcode.com/problems/cherry-pickup/ */
//You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.
//0 means the cell is empty, so you can pass through,
//1 means the cell contains a cherry that you can pick up and pass through, or
//-1 means the cell contains a thorn that blocks your way.
//Return the maximum number of cherries you can collect by following the rules below:
//Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
//After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
//When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
//If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.


class CherryPickup {
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        int[][][] dp = new int[n][n][n];
        for (int[][] d : dp) {
            for (int[] d1 : d) {
                Arrays.fill(d1, Integer.MIN_VALUE);
            }
        }
        dp[0][0][0] = grid[0][0];
        for (int t = 1; t <= 2 * n - 2; t++) {
            for (int i = Math.max(0, t - n + 1); i <= Math.min(n - 1, t); i++) {
                for (int j = Math.max(0, t - n + 1); j <= Math.min(n - 1, t); j++) {
                    if (grid[i][t - i] == -1 || grid[j][t - j] == -1) {
                        dp[i][j][t] = -1;
                        continue;
                    }
                    int val = grid[i][t - i];
                    if (i != j) {
                        val += grid[j][t - j];
                    }
                    for (int pi = i - 1; pi <= i; pi++) {
                        for (int pj = j - 1; pj <= j; pj++) {
                            if (pi >= 0 && pj >= 0) {
                                dp[i][j][t] = Math.max(dp[i][j][t], dp[pi][pj][t - 1] + val);
                            }
                        }
                    }
                }
            }
        }
        return Math.max(0, dp[n - 1][n - 1][2 * n - 2]);
        
    }
}
     
    