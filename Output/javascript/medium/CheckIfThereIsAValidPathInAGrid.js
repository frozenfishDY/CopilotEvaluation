/**https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/ */
//You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:
//1 which means a street connecting the left cell and the right cell.
//2 which means a street connecting the upper cell and the lower cell.
//3 which means a street connecting the left cell and the lower cell.
//4 which means a street connecting the right cell and the lower cell.
//5 which means a street connecting the left cell and the upper cell.
//6 which means a street connecting the right cell and the upper cell.
//You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.
//Notice that you are not allowed to change any street.
//Return true if there is a valid path in the grid or false otherwise.


/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var hasValidPath = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let visited = new Array(m).fill(0).map(() => new Array(n).fill(false));
    let queue = [[0, 0]];
    visited[0][0] = true;
    while (queue.length > 0) {
        let [i, j] = queue.shift();
        if (i === m - 1 && j === n - 1) {
            return true;
        }
        let street = grid[i][j];
        if (street === 1) {
            if (j + 1 < n && !visited[i][j + 1] && (grid[i][j + 1] === 1 || grid[i][j + 1] === 4 || grid[i][j + 1] === 6)) {
                queue.push([i, j + 1]);
                visited[i][j + 1] = true;
            }
            if (j - 1 >= 0 && !visited[i][j - 1] && (grid[i][j - 1] === 1 || grid[i][j - 1] === 3 || grid[i][j - 1] === 5)) {
                queue.push([i, j - 1]);
                visited[i][j - 1] = true;
            }
        } else if (street === 2) {
            if (i + 1 < m && !visited[i + 1][j] && (grid[i + 1][j] === 2 || grid[i + 1][j] === 3 || grid[i + 1][j] === 4)) {
                queue.push([i + 1, j]);
                visited[i + 1][j] = true;
            }
            if (i - 1 >= 0 && !visited[i - 1][j] && (grid[i - 1][j] === 2 || grid[i - 1][j] === 5 || grid[i - 1][j] === 6)) {
                queue.push([i - 1, j]);
                visited[i - 1][j] = true;
            }
        } else if (street === 3) {
            if (j + 1 < n && !visited[i][j + 1] && ( grid[i][j + 1] === 1 || grid[i][j + 1] === 4 || grid[i][j + 1] === 6)) {
                queue.push([i, j + 1]);
                visited[i][j + 1] = true;
            }
            if (i + 1 < m && !visited[i + 1][j] && (grid[i + 1][j] === 2 || grid[i + 1][j] === 3 || grid[i + 1][j] === 4)) {
                queue.push([i + 1, j]);
                visited[i + 1][j] = true;
            }
        } else if (street === 4) {
            if (j - 1 >= 0 && !visited[i][j - 1] && (grid[i][j - 1] === 1 || grid[i][j - 1] === 3 || grid[i][j - 1] === 5)) {
                queue.push([i, j - 1]);
                visited[i][j - 1] = true;
            }
            if (i + 1 < m && !visited[i + 1][j] && (grid[i + 1][j] === 2 || grid[i + 1][j] === 3 || grid[i + 1][j] === 4)) {
                queue.push([i + 1, j]);
                visited[i + 1][j] = true;
            }
        } else if (street === 5) { 
            if (j + 1 < n && !visited[i][j + 1] && (grid[i][j + 1] === 1 || grid[i][j + 1] === 4 || grid[i][j + 1] === 6)) {
                queue.push([i, j + 1]);
                visited[i][j + 1] = true;
            }
            if (i - 1 >= 0 && !visited[i - 1][j] && (grid[i - 1][j] === 2 || grid[i - 1][j] === 5 || grid[i - 1][j] === 6)) {
                queue.push([i - 1, j]);
                visited[i - 1][j] = true;
            }
        } else if (street === 6) {
            if (j - 1 >= 0 && !visited[i][j - 1] && (grid[i][j - 1] === 1 || grid[i][j - 1] === 3 || grid[i][j - 1] === 5)) {
                queue.push([i, j - 1]);
                visited[i][j - 1] = true;
            }
            if (i - 1 >= 0 && !visited[i - 1][j] && (grid[i - 1][j] === 2 || grid[i - 1][j] === 5 || grid[i - 1][j] === 6)) {
                queue.push([i - 1, j]);
                visited[i - 1][j] = true;
            }
        }

    }
    
};

    