/**https://leetcode.com/problems/as-far-from-land-as-possible/ */
//Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
//The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
// 
//Example 1:
//Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
//Output: 2
//Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
//Example 2:
//Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
//Output: 4
//Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 100
//	grid[i][j] is 0 or 1
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
    var n = grid.length;
	var q = [];
	var visited = Array(n).fill(0).map(() => Array(n).fill(0));
	for (var i = 0; i < n; i++) {
		for (var j = 0; j < n; j++) {
			visited[i][j] = grid[i][j] == 1 ? true : false;
			if (grid[i][j] == 1) {
				q.push({x:i, y:j});
			}
		}
	}
	if (q.length == 0 || q.length == n * n) {
		return -1;
	}
	var dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
	var ans = 0;
	while (q.length > 0) {
		var len = q.length;
		for (var i = 0; i < len; i++) {
			var cur = q.shift();
			for (var j = 0; j < 4; j++) {
				var x = cur.x + dirs[j][0];
				var y = cur.y + dirs[j][1];
				if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]) {
					visited[x][y] = true;
					q.push({x:x, y:y});
				}
			}
		}
		ans++;
	}
	return ans - 1;
};