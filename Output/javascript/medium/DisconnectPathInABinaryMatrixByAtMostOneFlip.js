/**https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/ */
//You are given a 0-indexed m x n binary matrix grid. You can move from a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1) that has the value 1. The matrix is disconnected if there is no path from (0, 0) to (m - 1, n - 1).
//You can flip the value of at most one (possibly none) cell. You cannot flip the cells (0, 0) and (m - 1, n - 1).
//Return true if it is possible to make the matrix disconnect or false otherwise.
//Note that flipping a cell changes its value from 0 to 1 or from 1 to 0.


/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var isPossibleToCutPath = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let visited = new Array(m);
    for(let i = 0; i < m; i++){
        visited[i] = new Array(n);
        for(let j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
    let queue = [[0, 0]];
    visited[0][0] = true;
    while(queue.length > 0){
        let [row, col] = queue.shift();
        if(row == m - 1 && col == n - 1){
            return true;
        }
        if(row + 1 < m && grid[row + 1][col] == 1 && !visited[row + 1][col]){
            queue.push([row + 1, col]);
            visited[row + 1][col] = true;
        }
        if(col + 1 < n && grid[row][col + 1] == 1 && !visited[row][col + 1]){
            queue.push([row, col + 1]);
            visited[row][col + 1] = true;
        }
    }
    return false;
    
};

    