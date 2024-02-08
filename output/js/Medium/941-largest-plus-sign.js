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
/**
 * @param {number} n
 * @param {number[][]} mines
 * @return {number}
 */
var orderOfLargestPlusSign = function(n, mines) {
    const minesSet = new Set();
    for (const mine of mines) {
        minesSet.add(`${mine[0]}-${mine[1]}`);
    }
    const dp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    let maxOrder = 0;
    for (let i = 0; i < n; i++) {
        let count = 0;
        for (let j = 0; j < n; j++) {
            count = minesSet.has(`${i}-${j}`) ? 0 : count + 1;
            dp[i][j] = count;
        }
        count = 0;
        for (let j = n - 1; j >= 0; j--) {
            count = minesSet.has(`${i}-${j}`) ? 0 : count + 1;
            dp[i][j] = Math.min(dp[i][j], count);
        }
    }
    for (let j = 0; j < n; j++) {
        let count = 0;
        for (let i = 0; i < n; i++) {
            count = minesSet.has(`${i}-${j}`) ? 0 : count + 1;
            dp[i][j] = Math.min(dp[i][j], count);
        }
        count = 0;
        for (let i = n - 1; i >= 0; i--) {
            count = minesSet.has(`${i}-${j}`) ? 0 : count + 1;
            dp[i][j] = Math.min(dp[i][j], count);
            maxOrder = Math.max(maxOrder, dp[i][j]);
        }
    }
    return maxOrder;
};