/**https://leetcode.com/problems/n-queens-ii/ */
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return the number of distinct solutions to the n-queens puzzle.


/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    let res = 0;
    let board = new Array(n);
    for(let i = 0; i < n; i++){
        board[i] = new Array(n).fill('.');
    }
    backtrack(board, 0, res);
    return res;
    
    
};

    