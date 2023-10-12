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
int orderOfLargestPlusSign(int n, int** mines, int minesSize, int* minesColSize){
int grid[n][n];
    for (int i = 0; i < n; i++) {
        memset(grid[i], 1, n * sizeof(int));
    }
    for (int i = 0; i < minesSize; i++) {
        grid[mines[i][0]][mines[i][1]] = 0;
    }
    int left[n][n];
    int right[n][n];
    int up[n][n];
    int down[n][n];
    for (int i = 0; i < n; i++) {
        left[i][0] = grid[i][0];
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 0) {
                left[i][j] = 0;
            } else {
                left[i][j] = left[i][j - 1] + 1;
            }
        }
        right[i][n - 1] = grid[i][n - 1];
        for (int j = n - 2; j >= 0; j--) {
            if (grid[i][j] == 0) {
                right[i][j] = 0;
            } else {
                right[i][j] = right[i][j + 1] + 1;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        up[0][j] = grid[0][j];
        for (int i = 1; i < n; i++) {
            if (grid[i][j] == 0) {
                up[i][j] = 0;
            } else {
                up[i][j] = up[i - 1][j] + 1;
            }
        }
        down[n - 1][j] = grid[n - 1][j];
        for (int i = n - 2; i >= 0; i--) {
            if (grid[i][j] == 0) {
                down[i][j] = 0;
            } else {
                down[i][j] = down[i + 1][j] + 1;
            }
        }
    }
    int max = 0;
    for (int j = 0; j < *minesColSize; j++) {
            int order = fmin(fmin(left[i][j], right[i][j]), fmin(up[i][j], down[i][j]));
            if (order > max) {
                max = order;
            }
        }
    return max;
}