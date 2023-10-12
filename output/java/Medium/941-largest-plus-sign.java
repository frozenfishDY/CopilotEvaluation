/**https://leetcode.com/problems/largest-plus-sign/ */
//You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.
//Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.
//An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.
// 
//Example 1:
//Input: n = 5, mines = [[4,2]]
//Output: 2
//Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
//Example 2:
//Input: n = 1, mines = [[0,0]]
//Output: 0
//Explanation: There is no plus sign, so return 0.
// 
//Constraints:
//	1 <= n <= 500
//	1 <= mines.length <= 5000
//	0 <= xi, yi < n
//	All the pairs (xi, yi) are unique.
class Solution {
    public int orderOfLargestPlusSign(int n, int[][] mines) {
        int[][] grid = new int[n][n];
        for(int[] row: grid) {
            Arrays.fill(row, n);
        }
        for(int[] mine: mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        for(int i=0; i<n; i++) {
            int left = 0;
            int right = 0;
            int up = 0;
            int down = 0;
            for(int j=0; j<n; j++) {
                left = grid[i][j] == 0 ? 0 : left + 1;
                grid[i][j] = Math.min(grid[i][j], left);
                right = grid[i][n-j-1] == 0 ? 0 : right + 1;
                grid[i][n-j-1] = Math.min(grid[i][n-j-1], right);
                up = grid[j][i] == 0 ? 0 : up + 1;
                grid[j][i] = Math.min(grid[j][i], up);
                down = grid[n-j-1][i] == 0 ? 0 : down + 1;
                grid[n-j-1][i] = Math.min(grid[n-j-1][i], down);
            }
        }
        int max = 0;
        for(int[] row: grid) {
            for(int cell: row) {
                max = Math.max(max, cell);
            }
        }
        return max;
    }
}