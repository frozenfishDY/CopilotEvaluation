/**https://leetcode.com/problems/unique-paths-iii/ */
//You are given an m x n integer array grid where grid[i][j] could be:
//1 representing the starting square. There is exactly one starting square.
//2 representing the ending square. There is exactly one ending square.
//0 representing empty squares we can walk over.
//-1 representing obstacles that we cannot walk over.
//Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.


/**
 * @param {number[][]} grid
 * @return {number}
 */
var uniquePathsIII = function(grid) {
    let start = [];
    let end = [];
    let empty = 0;
    for(let i = 0; i < grid.length; i++){
        for(let j = 0; j < grid[0].length; j++){
            if(grid[i][j] === 1){
                start = [i, j];
            }
            if(grid[i][j] === 2){
                end = [i, j];
            }
            if(grid[i][j] === 0){
                empty++;
            }
        }
    }
    let ans = 0;
    let dfs = function(i, j, empty){
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] === -1){
            return;
        }
        if(grid[i][j] === 2){
            if(empty === 0){
                ans++;
            }
            return;
        }
        grid[i][j] = -1;
        dfs(i + 1, j, empty - 1);
        dfs(i - 1, j, empty - 1);
        dfs(i, j + 1, empty - 1);
        dfs(i, j - 1, empty - 1);
        grid[i][j] = 0;
    };
    dfs(start[0], start[1], empty);
    return ans;
    
};

    