/**https://leetcode.com/problems/number-of-enclaves/ */
//You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
//A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
//Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var numEnclaves = function(grid) {
    let n = grid.length;
    let m = grid[0].length;
    let result = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(grid[i][j] == 1){
                result += dfs(grid, i, j);
            }
        }
    }
    return result;
    
    
    
};

    