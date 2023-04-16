/**https://leetcode.com/problems/sudoku-solver/ */
//Write a program to solve a Sudoku puzzle by filling the empty cells.
//A sudoku solution must satisfy all of the following rules:
//Each of the digits 1-9 must occur exactly once in each row.
//Each of the digits 1-9 must occur exactly once in each column.
//Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//The '.' character indicates empty cells.


/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    let row = new Array(9).fill(0).map(() => new Array(9).fill(false));
    let col = new Array(9).fill(0).map(() => new Array(9).fill(false));
    let box = new Array(9).fill(0).map(() => new Array(9).fill(false));
    let empty = [];
    for(let i = 0; i < 9; i++){
        for(let j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                let num = board[i][j] - 1;
                let k = Math.floor(i/3) * 3 + Math.floor(j/3);
                row[i][num] = true;
                col[j][num] = true;
                box[k][num] = true;
            }else{
                empty.push([i, j]);
            }
        }
    }
    let dfs = function(n){
        if(n == empty.length){
            return true;
        }
        let i = empty[n][0];
        let j = empty[n][1];
        let k = Math.floor(i/3) * 3 + Math.floor(j/3);
        for(let num = 0; num < 9; num++){
            if(!row[i][num] && !col[j][num] && !box[k][num]){
                row[i][num] = true;
                col[j][num] = true;
                box[k][num] = true;
                board[i][j] = String(num + 1);
                if(dfs(n + 1)){
                    return true;
                }
                board[i][j] = '.';
                row[i][num] = false;
                col[j][num] = false;
                box[k][num] = false;
            }
        }
        return false;
    }
    dfs(0);
    
};

    