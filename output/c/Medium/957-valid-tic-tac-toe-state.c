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


bool validTicTacToe(char ** board, int boardSize){
    int xCount = 0;
    int oCount = 0;
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
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
    int xWin = 0;
    int oWin = 0;
    for(int i = 0; i < boardSize; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if(board[i][0] == 'X'){
                xWin++;
            }
            if(board[i][0] == 'O'){
                oWin++;
            }
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            if(board[0][i] == 'X'){
                xWin++;
            }
            if(board[0][i] == 'O'){
                oWin++;
            }
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if(board[0][0] == 'X'){
            xWin++;
        }
        if(board[0][0] == 'O'){
            oWin++;
        }
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[0][2] == 'X'){
            xWin++;
        }
        if(board[0][2] == 'O'){
            oWin++;
        }
    }
    if(xWin > 0 && oWin > 0){
        return false;
    }
    if(xWin > 0 && xCount - oCount != 1){
        return false;
    }
    if(oWin > 0 && xCount != oCount){
        return false;
    }
    return true;

}

    