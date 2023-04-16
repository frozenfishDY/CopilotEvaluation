/**https://leetcode.com/problems/rotting-oranges/ */
//You are given an m x n grid where each cell can have one of three values:
//0 representing an empty cell,
//1 representing a fresh orange, or
//2 representing a rotten orange.
//Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
//Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let fresh = 0;
    let queue = [];
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(grid[i][j] == 1){
                fresh++;
            }
            if(grid[i][j] == 2){
                queue.push([i, j]);
            }
        }
    }
    let result = 0;
    while(queue.length > 0){
        let size = queue.length;
        for(let i = 0; i < size; i++){
            let [x, y] = queue.shift();
            if(x > 0 && grid[x - 1][y] == 1){
                grid[x - 1][y] = 2;
                fresh--;
                queue.push([x - 1, y]);
            }
            if(x < m - 1 && grid[x + 1][y] == 1){
                grid[x + 1][y] = 2;
                fresh--;
                queue.push([x + 1, y]);
            }
            if(y > 0 && grid[x][y - 1] == 1){
                grid[x][y - 1] = 2;
                fresh--;
                queue.push([x, y - 1]);
            }
            if(y < n - 1 && grid[x][y + 1] == 1){
                grid[x][y + 1] = 2;
                fresh--;
                queue.push([x, y + 1]);
            }
        }
        result++;
    }
    if(fresh > 0){
        return -1;
    }
    return result == 0 ? 0 : result - 1;
    
};

    