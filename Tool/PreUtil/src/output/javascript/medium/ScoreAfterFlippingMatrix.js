/**https://leetcode.com/problems/score-after-flipping-matrix/ */
//You are given an m x n binary matrix grid.
//A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
//Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
//Return the highest possible score after making any number of moves (including zero moves).


/**
 * @param {number[][]} grid
 * @return {number}
 */
var matrixScore = function(grid) {
    let result = 0;
    for(let i = 0; i < grid.length; i++){
        if(grid[i][0] == 0){
            for(let j = 0; j < grid[0].length; j++){
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    for(let j = 0; j < grid[0].length; j++){
        let count = 0;
        for(let i = 0; i < grid.length; i++){
            if(grid[i][j] == 1){
                count++;
            }
        }
        if(count < grid.length / 2){
            for(let i = 0; i < grid.length; i++){
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    for(let i = 0; i < grid.length; i++){
        for(let j = 0; j < grid[0].length; j++){
            result += grid[i][j] * Math.pow(2, grid[0].length - j - 1);
        }
    }
    return result;
    
};

    