/**https://leetcode.com/problems/magic-squares-in-grid/ */
//A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
//Given a row x col grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).


/**
 * @param {number[][]} grid
 * @return {number}
 */
var numMagicSquaresInside = function(grid) {
    let count = 0;
    for(let i = 0; i < grid.length - 2; i++){
        for(let j = 0; j < grid[0].length - 2; j++){
            if(grid[i + 1][j + 1] != 5){
                continue;
            }
            if(isMagic(grid, i, j)){
                count++;
            }
        }
    }
    return count;
    
    
    
};

    