#https://leetcode.com/problems/sudoku-solver/
#Write a program to solve a Sudoku puzzle by filling the empty cells.
#A sudoku solution must satisfy all of the following rules:
#Each of the digits 1-9 must occur exactly once in each row.
#Each of the digits 1-9 must occur exactly once in each column.
#Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
#The '.' character indicates empty cells.


class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        self.solve(board)
        
    