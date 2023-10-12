#https://leetcode.com/problems/minesweeper/
#Let's play the minesweeper game (Wikipedia, online game)!
#You are given an m x n char matrix board representing the game board where:
#	'M' represents an unrevealed mine,
#	'E' represents an unrevealed empty square,
#	'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
#	digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
#	'X' represents a revealed mine.
#You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').
#Return the board after revealing this position according to the following rules:
#	If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
#	If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
#	If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
#	Return the board when no more squares will be revealed.
# 
#Example 1:
#Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
#Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
#Example 2:
#Input: board = [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]], click = [1,2]
#Output: [["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
# 
#Constraints:
#	m == board.length
#	n == board[i].length
#	1 <= m, n <= 50
#	board[i][j] is either 'M', 'E', 'B', or a digit from '1' to '8'.
#	click.length == 2
#	0 <= clickr < m
#	0 <= clickc < n
#	board[clickr][clickc] is either 'M' or 'E'.
class Solution(object):
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        #Solution
        #1. If click is 'M', change it to 'X' and return the board
        #2. If click is 'E', check the adjacent cells. If there is a 'M', change it to '1' and return the board
        #3. If click is 'B', change it to 'B' and check the adjacent cells. If there is a 'M', change it to '1' and return the board
        #4. If click is '1' to '8', change it to 'B' and return the board
        #
        #Example:
        #board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
        #ret: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
        #
        #Time complexity: O(mn)
        #Space complexity: O(mn)

        def check(row, col):
            if row < 0 or row >= len(board) or col < 0 or col >= len(board[0]):
                return
            if board[row][col] == 'M':
                board[row][col] = '1'
            elif board[row][col] == 'E':
                board[row][col] = 'B'
                for i in range(-1, 2):
                    for j in range(-1, 2):
                        if i == 0 and j == 0:
                            continue
                        check(row + i, col + j)
            elif board[row][col] in '12345678':
                board[row][col] = 'B'

        row, col = click
        if board[row][col] == 'M':
            board[row][col] = 'X'
        elif board[row][col] == 'E':
            check(row, col)

        return board