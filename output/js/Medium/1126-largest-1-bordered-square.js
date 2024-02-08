/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]_x000D_
//Output: 9_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,1,0,0]]_x000D_
//Output: 1_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= grid.length <= 100_x000D_
//	1 <= grid[0].length <= 100_x000D_
//	grid[i][j] is 0 or 1_x000D_
/**
 * @param {number[][]} grid
 * @return {number}
 */
var largest1BorderedSquare = function(grid) {
    var ans = 0;
	var m = grid.length;
	var n = grid[0].length;
	var hor = Array(m).fill(0).map(() => Array(n).fill(0));
	var ver = Array(m).fill(0).map(() => Array(n).fill(0));
	for (var i = 0; i < m; i++) {
		for (var j = 0; j < n; j++) {
			if (grid[i][j] == 1) {
				hor[i][j] = j > 0 ? hor[i][j - 1] + 1 : 1;
				ver[i][j] = i > 0 ? ver[i - 1][j] + 1 : 1;
			}
		}
	}
	for (var i = m - 1; i >= 0; i--) {
		for (var j = n - 1; j >= 0; j--) {
			var small = Math.min(hor[i][j], ver[i][j]);
			while (small > ans) {
				if (ver[i][j - small + 1] >= small && hor[i - small + 1][j] >= small) {
					ans = small;
				}
				small--;
			}
		}
	}
	return ans * ans;
};