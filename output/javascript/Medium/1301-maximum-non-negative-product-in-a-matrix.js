/**https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/ */
//You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
//Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
//Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.
//Notice that the modulo is performed after getting the maximum product.
// 
//Example 1:
//Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
//Output: -1
//Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
//Example 2:
//Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
//Output: 8
//Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).
//Example 3:
//Input: grid = [[1,3],[0,-4]]
//Output: 0
//Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 15
//	-4 <= grid[i][j] <= 4
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxProductPath = function(grid) {
    const mod = 1000000007;
    const m = grid.length, n = grid[0].length;
    const dpMax = new Array(m).fill(0).map(() => new Array(n).fill(0));
    const dpMin = new Array(m).fill(0).map(() => new Array(n).fill(0));
    dpMax[0][0] = dpMin[0][0] = grid[0][0];
    for (let i = 1; i < m; i++) {
        dpMax[i][0] = dpMin[i][0] = dpMax[i - 1][0] * grid[i][0];
    }
    for (let j = 1; j < n; j++) {
        dpMax[0][j] = dpMin[0][j] = dpMax[0][j - 1] * grid[0][j];
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            const max = Math.max(dpMax[i - 1][j], dpMax[i][j - 1]);
            const min = Math.min(dpMin[i - 1][j], dpMin[i][j - 1]);
            dpMax[i][j] = Math.max(max * grid[i][j], min * grid[i][j]);
            dpMin[i][j] = Math.min(max * grid[i][j], min * grid[i][j]);
        }
    }
    return dpMax[m - 1][n - 1] < 0 ? -1 : dpMax[m - 1][n - 1] % mod;

};