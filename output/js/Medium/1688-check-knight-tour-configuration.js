/**https://leetcode.com/problems/check-knight-tour-configuration/ */
//There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every cell on the board exactly once.
//You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] where grid[row][col] indicates that the cell (row, col) is the grid[row][col]th cell that the knight visited. The moves are 0-indexed.
//Return true if grid represents a valid configuration of the knight's movements or false otherwise.
//Note that a valid knight move consists of moving two squares vertically and one square horizontally, or two squares horizontally and one square vertically. The figure below illustrates all the possible eight moves of a knight from some cell.
// 
//Example 1:
//Input: grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
//Output: true
//Explanation: The above diagram represents the grid. It can be shown that it is a valid configuration.
//Example 2:
//Input: grid = [[0,3,6],[5,8,1],[2,7,4]]
//Output: false
//Explanation: The above diagram represents the grid. The 8th move of the knight is not valid considering its position after the 7th move.
// 
//Constraints:
//	n == grid.length == grid[i].length
//	3 <= n <= 7
//	0 <= grid[row][col] < n * n
//	All integers in grid are unique.
/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var checkValidGrid = function(grid) {
    let n = grid.length;
    let map = new Map();
    let visited = new Array(n*n).fill(0);
    let directions = [[-2,1],[-2,-1],[-1,2],[-1,-2],[1,2],[1,-2],[2,1],[2,-1]];
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++ ) {
            map.set(grid[i][j], [i,j]);
        }
    }
    for (let i = 0; i < n*n; i++) {
        let [x,y] = map.get(i);
        if (visited[i] === 0) {
            visited[i] = 1;
            for (let j = 0; j < directions.length; j++) {
                let [dx, dy] = directions[j];
                let newX = x + dx;
                let newY = y + dy;
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && visited[grid[newX][newY]] === 0) {
                    visited[grid[newX][newY]] = 1;
                }
            }
        }
    }
    return visited.every(val => val === 1);
};