#https://leetcode.com/problems/valid-sudoku/
#Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
#Each row must contain the digits 1-9 without repetition.
#Each column must contain the digits 1-9 without repetition.
#Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
#Note:
#A Sudoku board (partially filled) could be valid but is not necessarily solvable.
#Only the filled cells need to be validated according to the mentioned rules.
# 


class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
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
        

    