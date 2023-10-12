#https://leetcode.com/problems/battleships-in-a-board/
#Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.
#Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
# 
#Example 1:
#Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
#Output: 2
#Example 2:
#Input: board = [["."]]
#Output: 0
# 
#Constraints:
#	m == board.length
#	n == board[i].length
#	1 <= m, n <= 200
#	board[i][j] is either '.' or 'X'.
# 
#Follow up: Could you do it in one-pass, using only O(1) extra memory and without modifying the values board?
class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        #Solution
        #1. Count the number of 'X' which is not adjacent to another 'X' in the left or up direction.
        #2. Return the count
        #
        #Example:
        #board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
        #count: 2
        #
        #Time complexity: O(m*n)
        #Space complexity: O(1)

        count = 0
        for row in range(len(board)):
            for col in range(len(board[0])):
                if board[row][col] == 'X' and (row == 0 or board[row-1][col] == '.') and (col == 0 or board[row][col-1] == '.'):
                    count += 1

        return count