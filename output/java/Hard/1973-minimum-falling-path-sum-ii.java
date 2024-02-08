/**https://leetcode.com/problems/minimum-falling-path-sum-ii/ */
//Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
//A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.


class MinimumFallingPathSumIi {
    public int minFallingPathSum(int[][] grid) {
        int n = grid.length;
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            int min = Integer.MAX_VALUE;
            int min2 = Integer.MAX_VALUE;
            for (int j = 0; j < n; j++) {
                if (dp[i - 1][j] < min) {
                    min2 = min;
                    min = dp[i - 1][j];
                } else if (dp[i - 1][j] < min2) {
                    min2 = dp[i - 1][j];
                }
            }
            for (int j = 0; j < n; j++) {
                if (dp[i - 1][j] == min) {
                    dp[i][j] = min2 + grid[i][j];
                } else {
                    dp[i][j] = min + grid[i][j];
                }
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            res = Math.min(res, dp[n - 1][i]);
        }
        return res;
        
    }
}
     
    