/**https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/ */
//Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.


class TilingARectangleWithTheFewestSquares {
    public int tilingRectangle(int n, int m) {
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = Integer.MAX_VALUE;
                    for (int k = 1; k <= i / 2; k++) {
                        dp[i][j] = Math.min(dp[i][j], dp[k][j] + dp[i - k][j]);
                    }
                    for (int k = 1; k <= j / 2; k++) {
                        dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[i][j - k]);
                    }
                }
            }
        }
        return dp[n][m];
        
    }
}
     
    