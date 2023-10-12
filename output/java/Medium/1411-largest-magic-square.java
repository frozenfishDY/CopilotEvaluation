/**https://leetcode.com/problems/largest-magic-square/ */
//A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.
//Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.
// 
//Example 1:
//Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
//Output: 3
//Explanation: The largest magic square has a size of 3.
//Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
//- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
//- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
//- Diagonal sums: 5+4+3 = 6+4+2 = 12
//Example 2:
//Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
//Output: 2
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j] <= 106
class Solution {
    public int largestMagicSquare(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][][] sum = new int[m][n][4];
        sum[0][0][0] = grid[0][0];
        sum[0][0][1] = grid[0][0];
        sum[0][0][2] = grid[0][0];
        sum[0][0][3] = grid[0][0];
        for (int i = 1; i < m; i++) {
            sum[i][0][0] = grid[i][0];
            sum[i][0][1] = grid[i][0];
            sum[i][0][2] = grid[i][0];
            sum[i][0][3] = grid[i][0];
            for (int j = 1; j < n; j++) {
                sum[i][j][0] = sum[i - 1][j - 1][0] + grid[i][j];
                sum[i][j][1] = sum[i - 1][j - 1][1] + grid[i][j];
                sum[i][j][2] = sum[i - 1][j - 1][2] + grid[i][j];
                sum[i][j][3] = sum[i - 1][j - 1][3] + grid[i][j];
            }
        }
        for (int i = 1; i < m; i++) {
            sum[i][n - 1][1] = grid[i][n - 1];
            sum[i][n - 1][2] = grid[i][n - 1];
            sum[i][n - 1][3] = grid[i][n - 1];
            for (int j = n - 2; j >= 0; j--) {
                sum[i][j][1] = sum[i - 1][j + 1][1] + grid[i][j];
                sum[i][j][2] = sum[i - 1][j + 1][2] + grid[i][j];
                sum[i][j][3] = sum[i - 1][j + 1][3] + grid[i][j];
            }
        }
        for (int i = m - 2; i >= 0; i--) {
            sum[i][n - 1][2] = grid[i][n - 1];
            sum[i][n - 1][3] = grid[i][n - 1];
            for (int j = n - 2; j >= 0; j--) {
                sum[i][j][2] = sum[i + 1][j + 1][2] + grid[i][j];
                sum[i][j][3] = sum[i + 1][j + 1][3] + grid[i][j];
            }
        }
        for (int i = m - 2; i >= 0; i--) {
            sum[i][0][3] = grid[i][0];
            for (int j = 1; j < n; j++) {
                sum[i][j][3] = sum[i + 1][j - 1][3] + grid[i][j];
            }
        }
        for (int k = Math.min(m, n); k >= 1; k--) {
            for (int i = k - 1; i < m; i++) {
                for (int j = k - 1; j < n; j++) {
                    if (check(sum, i, j, k)) {
                        return k;
                    }
                }
            }
        }
        return 0;
    }
    private boolean check(int[][][] sum, int i, int j, int k) {
        int a = sum[i][j][0] - (j - k >= 0 ? sum[i][j - k][0] : 0);
        int b = sum[i][j][1] - (i - k >= 0 ? sum[i - k][j][1] : 0);
        int c = sum[i][j][2] - (i - k >= 0 && j - k >= 0 ? sum[i - k][j - k][2] : 0);
        int d = sum[i][j][3] - (i - k >= 0 && j + k < sum[0].length ? sum[i - k][j + k][3] : 0);
        return a == b && b == c && c == d;
    }
}