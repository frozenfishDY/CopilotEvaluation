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


class ValidTicTacToeState {
    public boolean validTicTacToe(String[] board) {
        int n = board.length;
        int x = 0;
        int o = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i].charAt(j) == 'X'){
                    x++;
                }else if(board[i].charAt(j) == 'O'){
                    o++;
                }
            }
        }
        if(o > x || x - o > 1){
            return false;
        }
        boolean xWin = false;
        boolean oWin = false;
        for(int i = 0; i < n; i++){
            if(board[i].equals("XXX")){
                xWin = true;
            }
            if(board[i].equals("OOO")){
                oWin = true;
            }
            if(board[0].charAt(i) == board[1].charAt(i) && board[1].charAt(i) == board[2].charAt(i)){
                if(board[0].charAt(i) == 'X'){
                    xWin = true;
                }
                if(board[0].charAt(i) == 'O'){
                    oWin = true;
                }
            }
        }
        if(board[0].charAt(0) == board[1].charAt(1) && board[1].charAt(1) == board[2].charAt(2)){
            if(board[0].charAt(0) == 'X'){
                xWin = true;
            }
            if(board[0].charAt(0) == 'O'){
                oWin = true;
            }
        }
        if(board[0].charAt(2) == board[1].charAt(1) && board[1].charAt(1) == board[2].charAt(0)){
            if(board[0].charAt(2) == 'X'){
                xWin = true;
            }
            if(board[0].charAt(2) == 'O'){
                oWin = true;
            }
        }
        if(xWin && oWin){
            return false;
        }
        if(xWin && x == o){
            return false;
        }
        if(oWin && x > o){
            return false;
        }
        return true;
        
    }
}

    