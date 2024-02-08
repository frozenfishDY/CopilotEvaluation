/**https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ */
//Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).


class LongestIncreasingPathInAMatrix {
    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] left = new int[m][n];
        int[][] right = new int[m][n];
        int[][] up = new int[m][n];
        int[][] down = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                left[i][j] = 1;
                right[i][j] = 1;
                up[i][j] = 1;
                down[i][j] = 1;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] > matrix[i][j - 1]) {
                    left[i][j] = left[i][j - 1] + 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = n - 2; j >= 0; j--) {
                if (matrix[i][j] > matrix[i][j + 1]) {
                    right[i][j] = right[i][j + 1] + 1;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (matrix[i][j] > matrix[i - 1][j]) {
                    up[i][j] = up[i - 1][j] + 1;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = m - 2; i >= 0; i--) {
                if (matrix[i][j] > matrix[i + 1][j]) {
                    down[i][j] = down[i + 1][j] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = Math.max(ans, left[i][j] + right[i][j + 1] - 1);
                ans = Math.max(ans, up[i][j] + down[i + 1][j] - 1);

                
        
    }
}
     
    