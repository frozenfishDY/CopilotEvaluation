/**https://leetcode.com/problems/valid-tic-tac-toe-state/ */
//Given a Tic-Tac-Toe board as a string array board, return true if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
//The board is a 3 x 3 array that consists of characters ' ', 'X', and 'O'. The ' ' character represents an empty square.
//Here are the rules of Tic-Tac-Toe:
//Players take turns placing characters into empty squares ' '.
//The first player always places 'X' characters, while the second player always places 'O' characters.
//'X' and 'O' characters are always placed into empty squares, never filled ones.
//The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
//The game also ends if all squares are non-empty.
//No more moves can be played if the game is over.


/**
 * @param {string[]} board
 * @return {boolean}
 */
var validTicTacToe = function(board) {
    let xCount = 0;
    let oCount = 0;
    for(let i = 0; i < 3; i++){
        for(let j = 0; j < 3; j++){
            if(board[i][j] == 'X'){
                xCount++;
            }
            if(board[i][j] == 'O'){
                oCount++;
            }
        }
    }
    if(oCount > xCount || xCount - oCount > 1){
        return false;
    }
    let xWin = checkWin(board, 'X');
    let oWin = checkWin(board, 'O');
    if(xWin && oWin){
        return false;
    }
    if(xWin && xCount == oCount){
        return false;
    }
    if(oWin && xCount > oCount){
        return false;
    }
    return true;
    
    
    
};

    