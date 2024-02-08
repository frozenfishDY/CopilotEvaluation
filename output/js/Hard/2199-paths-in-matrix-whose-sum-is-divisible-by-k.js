/**https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/ */
//You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.
//Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
//Output: 2
//Explanation: There are two paths where the sum of the elements on the path is divisible by k.
//The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
//The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.
//Example 2:
//Input: grid = [[0,0]], k = 5
//Output: 1
//Explanation: The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.
//Example 3:
//Input: grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
//Output: 10
//Explanation: Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 5 * 104
//	1 <= m * n <= 5 * 104
//	0 <= grid[i][j] <= 100
//	1 <= k <= 50
/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var numberOfPaths = function(grid, k) {
    let m = grid.length;
    let n = grid[0].length;
    let mod = 1000000007;
    let dp = new Array(m).fill(0).map(() => new Array(n).fill(0));
    dp[0][0] = grid[0][0];
    let directions = [[0, 1], [1, 0]];
    let queue = [[0, 0]];
    let visited = new Array(m).fill(0).map(() => new Array(n).fill(false));
    visited[0][0] = true;
    while (queue.length > 0) {
        let [i, j] = queue.shift();
        for (let [di, dj] of directions) {
            let ni = i + di;
            let nj = j + dj;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
                dp[ni][nj] = (dp[i][j] + grid[ni][nj]) % k;
                queue.push([ni, nj]);
                visited[ni][nj] = true;
            }
        }
    }
    let result = 0;
    for (let i = 0; i < m; i++) {
        if (dp[i][n - 1] === 0) {
            result++;
        }
    }
    for (let j = 0; j < n; j++) {
        if (dp[m - 1][j] === 0) {
            result++;
        }
    }
    return result;
};