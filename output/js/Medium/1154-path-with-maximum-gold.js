/**https://leetcode.com/problems/path-with-maximum-gold/ */
//In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.
//Return the maximum amount of gold you can collect under the conditions:
//	Every time you are located in a cell you will collect all the gold in that cell.
//	From your position, you can walk one step to the left, right, up, or down.
//	You can't visit the same cell more than once.
//	Never visit a cell with 0 gold.
//	You can start and stop collecting gold from any position in the grid that has some gold.
// 
//Example 1:
//Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
//Output: 24
//Explanation:
//[[0,6,0],
// [5,8,7],
// [0,9,0]]
//Path to get the maximum gold, 9 -> 8 -> 7.
//Example 2:
//Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
//Output: 28
//Explanation:
//[[1,0,7],
// [2,0,6],
// [3,4,5],
// [0,3,0],
// [9,0,20]]
//Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 15
//	0 <= grid[i][j] <= 100
//	There are at most 25 cells containing gold.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var getMaximumGold = function(grid) {
    var n = grid.length;
	var m = grid[0].length;
	var dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
	var visited = Array(n).fill(0).map(() => Array(m).fill(0));
	var dfs = function(i, j, sum) {
		var ans = sum;
		for (var k = 0; k < 4; k++) {
			var x = i + dirs[k][0];
			var y = j + dirs[k][1];
			if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0 && visited[x][y] == 0) {
				visited[x][y] = 1;
				ans = Math.max(ans, dfs(x, y, sum + grid[x][y]));
				visited[x][y] = 0;
			}
		}
		return ans;
	};
	var ans = 0;
	for (var i = 0; i < n; i++) {
		for (var j = 0; j < m; j++) {
			if (grid[i][j] != 0) {
				visited[i][j] = 1;
				ans = Math.max(ans, dfs(i, j, grid[i][j]));
				visited[i][j] = 0;
			}
		}
	}
	return ans;
};