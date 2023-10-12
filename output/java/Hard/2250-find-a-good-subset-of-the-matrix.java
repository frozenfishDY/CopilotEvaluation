/**https://leetcode.com/problems/find-a-good-subset-of-the-matrix/ */
//You are given a 0-indexed m x n binary matrix grid.
//Let us call a non-empty subset of rows good if the sum of each column of the subset is at most half of the length of the subset.
//More formally, if the length of the chosen subset of rows is k, then the sum of each column should be at most floor(k / 2).
//Return an integer array that contains row indices of a good subset sorted in ascending order.
//If there are multiple good subsets, you can return any of them. If there are no good subsets, return an empty array.
//A subset of rows of the matrix grid is any matrix that can be obtained by deleting some (possibly none or all) rows from grid.
// 
//Example 1:
//Input: grid = [[0,1,1,0],[0,0,0,1],[1,1,1,1]]
//Output: [0,1]
//Explanation: We can choose the 0th and 1st rows to create a good subset of rows.
//The length of the chosen subset is 2.
//- The sum of the 0th column is 0 + 0 = 0, which is at most half of the length of the subset.
//- The sum of the 1st column is 1 + 0 = 1, which is at most half of the length of the subset.
//- The sum of the 2nd column is 1 + 0 = 1, which is at most half of the length of the subset.
//- The sum of the 3rd column is 0 + 1 = 1, which is at most half of the length of the subset.
//Example 2:
//Input: grid = [[0]]
//Output: [0]
//Explanation: We can choose the 0th row to create a good subset of rows.
//The length of the chosen subset is 1.
//- The sum of the 0th column is 0, which is at most half of the length of the subset.
//Example 3:
//Input: grid = [[1,1,1],[1,1,1]]
//Output: []
//Explanation: It is impossible to choose any subset of rows to create a good subset.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m <= 104
//	1 <= n <= 5
//	grid[i][j] is either 0 or 1.
class Solution {
    public List<Integer> goodSubsetofBinaryMatrix(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dp = new int[m][n];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans = Math.max(ans, dfs(i, 0, grid, dp));
        }
        return ans;
    }
    private int dfs(int i, int j, int[][] grid, int[][] dp) {
        int m = grid.length, n = grid[0].length;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 1;
        for (int k = i - 1; k <= i + 1; ++k) {
            if (k < 0 || k >= m) {
                continue;
            }
            for (int l = j - 1; l <= j + 1; ++l) {
                if (l < 0 || l >= n || k == i && l == j) {
                    continue;
                }
                if (grid[k][l] > grid[i][j]) {
                    ans = Math.max(ans, 1 + dfs(k, l, grid, dp));
                }
            }
        }
        return dp[i][j] = ans;

    }
}