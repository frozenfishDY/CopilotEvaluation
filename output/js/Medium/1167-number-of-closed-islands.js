/**https://leetcode.com/problems/number-of-closed-islands/ */
//Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
//Return the number of closed islands.
// 
//Example 1:
//Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
//Output: 2
//Explanation: 
//Islands in gray are closed because they are completely surrounded by water (group of 1s).
//Example 2:
//Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
//Output: 1
//Example 3:
//Input: grid = [[1,1,1,1,1,1,1],
//               [1,0,0,0,0,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,1,0,1,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,0,0,0,0,1],
//               [1,1,1,1,1,1,1]]
//Output: 2
// 
//Constraints:
//	1 <= grid.length, grid[0].length <= 100
//	0 <= grid[i][j] <=1
/**
 * @param {number[][]} grid
 * @return {number}
 */
var closedIsland = function(grid) {
    var m = grid.length;
	var n = grid[0].length;
	var visited = Array(m).fill(0).map(() => Array(n).fill(0));
	var dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
	var ans = 0;
	for (var i = 0; i < m; i++) {
		for (var j = 0; j < n; j++) {
			if (grid[i][j] == 0 && !visited[i][j]) {
				var q = [];
				var flag = true;
				q.push({x:i, y:j});
				visited[i][j] = true;
				while (q.length > 0) {
					var cur = q.shift();
					for (var k = 0; k < 4; k++) {
						var x = cur.x + dirs[k][0];
						var y = cur.y + dirs[k][1];
						if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y]) {
							visited[x][y] = true;
							q.push({x:x, y:y});
						}
					}
					if (cur.x == 0 || cur.x == m - 1 || cur.y == 0 || cur.y == n - 1) {
						flag = false;
					}
				}
				if (flag) {
					ans++;
				}
			}
		}
	}
	return ans;
};