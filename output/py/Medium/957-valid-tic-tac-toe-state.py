#https://leetcode.com/problems/valid-tic-tac-toe-state/
#Given a Tic-Tac-Toe board as a string array board, return true if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
#The board is a 3 x 3 array that consists of characters ' ', 'X', and 'O'. The ' ' character represents an empty square.
#Here are the rules of Tic-Tac-Toe:
#Players take turns placing characters into empty squares ' '.
#The first player always places 'X' characters, while the second player always places 'O' characters.
#'X' and 'O' characters are always placed into empty squares, never filled ones.
#The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
#The game also ends if all squares are non-empty.
#No more moves can be played if the game is over.


class Solution(object):
    def validTicTacToe(self, board):
        """
        :type board: List[str]
        :rtype: bool
        """
        #check rows
        for row in board:
            if not self.isValid(row):
                return False
        #check columns
        for i in range(9):
            col = [board[j][i] for j in range(9)]
            if not self.isValid(col):
                return False
        #check 3x3 boxes
        for i in range(3):
            for j in range(3):
                box = [board[m][n] for m in range(3*i,3*i+3) for n in range(3*j,3*j+3)]
                if not self.isValid(box):
                    return False
        return True
        

    