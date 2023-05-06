/**https://leetcode.com/problems/valid-sudoku/ */
//Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//Each row must contain the digits 1-9 without repetition.
//Each column must contain the digits 1-9 without repetition.
//Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//Note:
//A Sudoku board (partially filled) could be valid but is not necessarily solvable.
//Only the filled cells need to be validated according to the mentioned rules.
// 


/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    let rows = {};
    let cols = {};
    let boxes = {};
    for(let i = 0; i < 9; i++){
        rows[i] = {};
        cols[i] = {};
        boxes[i] = {};
    }
    for(let i = 0; i < 9; i++){
        for(let j = 0; j < 9; j++){
            let boxIndex = Math.floor(i / 3) * 3 + Math.floor(j / 3);
            let num = board[i][j];
            if(num != "."){
                if(rows[i][num] || cols[j][num] || boxes[boxIndex][num]){
                    return false;
                }
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[boxIndex][num] = true;
            }
        }
    }
    return true;
    
};

    