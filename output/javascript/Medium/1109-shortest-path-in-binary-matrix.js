/**https://leetcode.com/problems/shortest-path-in-binary-matrix/ */
//Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
//A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
//	All the visited cells of the path are 0.
//	All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
//The length of a clear path is the number of visited cells of this path.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 2
//Example 2:
//Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
//Output: 4
//Example 3:
//Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
//Output: -1
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 100
//	grid[i][j] is 0 or 1
/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestPathBinaryMatrix = function(grid) {
    if (grid[0][0] !== 0) {
        return -1;
    }
    let queue = [[0, 0]];
    let steps = 0;
    while (queue.length) {
        steps++;
        const nextQueue = [];
        for (let i = 0; i < queue.length; i++) {
            const [x, y] = queue[i];
            if (x === grid.length - 1 && y === grid[0].length - 1) {
                return steps;
            }
            grid[x][y] = 1;
            if (x > 0 && y > 0 && grid[x - 1][y - 1] === 0) {
                nextQueue.push([x - 1, y - 1]);
            }
            if (x > 0 && grid[x - 1][y] === 0) {
                nextQueue.push([x - 1, y]);
            }
            if (x > 0 && y < grid[0].length - 1 && grid[x - 1][y + 1] === 0) {
                nextQueue.push([x - 1, y + 1]);
            }
            if (y > 0 && grid[x][y - 1] === 0) {
                nextQueue.push([x, y - 1]);
            }
            if (y < grid[0].length - 1 && grid[x][y + 1] === 0) {
                nextQueue.push([x, y + 1]);
            }
            if (x < grid.length - 1 && y > 0 && grid[x + 1][y - 1] === 0) {
                nextQueue.push([x + 1, y - 1]);
            }
            if (x < grid.length - 1 && grid[x + 1][y] === 0) {
                nextQueue.push([x + 1, y]);
            }
            if (x < grid.length - 1 && y < grid[0].length - 1 && grid[x + 1][y + 1] === 0) {
                nextQueue.push([x + 1, y + 1]);
            }
        }
        queue = nextQueue;
    }
    return -1;


};