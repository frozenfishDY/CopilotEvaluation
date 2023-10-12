/**https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/ */
//You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:
//	A land cell if grid[r][c] = 0, or
//	A water cell containing grid[r][c] fish, if grid[r][c] > 0.
//A fisher can start at any water cell (r, c) and can do the following operations any number of times:
//	Catch all the fish at cell (r, c), or
//	Move to any adjacent water cell.
//Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
//An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.
// 
//Example 1:
//Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
//Output: 7
//Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
//Example 2:
//Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
//Output: 1
//Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 10
//	0 <= grid[i][j] <= 10
class Solution {
    public int findMaxFish(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][][] dp = new int[m][n][2];
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int res = 0;
        for (int i = 0; i < m; i++) {
            Arrays.fill(dp[i][0], grid[i][0]);
            res = Math.max(res, dp[i][0][0]);
        }
        for (int j = 0; j < n; j++) {
            dp[0][j][1] = grid[0][j];
            res = Math.max(res, dp[0][j][1]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n - 1; j++) {
                dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i][j - 1][0]) + grid[i][j];
                res = Math.max(res, dp[i][j][0]);
            }
            for (int j = n - 2; j >= 1; j--) {
                dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i][j + 1][1]) + grid[i][j];
                res = Math.max(res, dp[i][j][1]);
            }
        }
        return res;
    }
}