/**https://leetcode.com/problems/path-with-minimum-effort/ */
//You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort._x000D_
//_x000D_
//A route's effort is the maximum absolute difference in heights between two consecutive cells of the route._x000D_
//_x000D_
//Return the minimum effort required to travel from the top-left cell to the bottom-right cell._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: heights = [[1,2,2],[3,8,2],[5,3,5]]_x000D_
//Output: 2_x000D_
//Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells._x000D_
//This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: heights = [[1,2,3],[3,8,4],[5,3,5]]_x000D_
//Output: 1_x000D_
//Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5]._x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]_x000D_
//Output: 0_x000D_
//Explanation: This route does not require any effort._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	rows == heights.length_x000D_
//	columns == heights[i].length_x000D_
//	1 <= rows, columns <= 100_x000D_
//	1 <= heights[i][j] <= 106_x000D_
/**_x000D_
 * @param {number[][]} heights_x000D_
 * @return {number}_x000D_
 */_x000D_
var minimumEffortPath = function(heights) {
    let m = heights.length;
    let n = heights[0].length;
    let dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    let queue = [];
    queue.push([0, 0]);
    let visited = new Array(m).fill(0).map(() => new Array(n).fill(0));
    while (queue.length) {
        let cur = queue.shift();
        if (visited[cur[0]][cur[1]]) continue;
        visited[cur[0]][cur[1]] = true;
        for (let dir of dirs) {
            let x = cur[0] + dir[0];
            let y = cur[1] + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
            let diff = Math.abs(heights[cur[0]][cur[1]] - heights[x][y]);
            queue.push([x, y, Math.max(diff, cur[2])]);
        }
    }
    return visited[m - 1][n - 1];
};