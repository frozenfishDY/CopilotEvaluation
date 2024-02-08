/**https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/ */
//Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.
//Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
//A binary matrix is a matrix with all cells equal to 0 or 1 only.
//A zero matrix is a matrix with all cells equal to 0.


class MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrix {
    public int minFlips(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (mat[i - 1][j - 1] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + 1 - dp[i - 1][j - 1];
                }
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int count = dp[i][j] + dp[m][n] - dp[i][n] - dp[m][j];
                if (count % 2 == 0) {
                    res = Math.min(res, count / 2);
                }
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
        
    }
}
     
    