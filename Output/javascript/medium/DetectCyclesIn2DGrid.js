/**https://leetcode.com/problems/detect-cycles-in-2d-grid/ */
//Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
//A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.
//Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.
//Return true if any cycle of the same value exists in grid, otherwise, return false.


/**
 * @param {character[][]} grid
 * @return {boolean}
 */
var containsCycle = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let visited = new Array(m);
    for (let i = 0; i < m; i++) {
        visited[i] = new Array(n).fill(false);
    }
    let dfs = (i, j, pi, pj, c) => {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != c || visited[i][j]) {
            return false;
        }
        if (i == pi && j == pj) {
            return false;
        }
        if (visited[i][j]) {
            return true;
        }
        visited[i][j] = true;
        let res = dfs(i + 1, j, i, j, c) || dfs(i - 1, j, i, j, c) || dfs(i, j + 1, i, j, c) || dfs(i, j - 1, i, j, c);
        visited[i][j] = false;
        return res;
    }
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (dfs(i, j, -1, -1, grid[i][j])) {
                return true;
            }
        }
    }
    return false;
    
};

    