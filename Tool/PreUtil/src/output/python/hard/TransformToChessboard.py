#https://leetcode.com/problems/transform-to-chessboard/
#You are given an n x n binary grid board. In each move, you can swap any two rows with each other, or any two columns with each other.
#Return the minimum number of moves to transform the board into a chessboard board. If the task is impossible, return -1.
#A chessboard board is a board where no 0's and no 1's are 4-directionally adjacent.


class Solution(object):
    def movesToChessboard(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        # 1. check if the board is valid
        # 2. find the number of moves to make the board a chessboard
        # 3. return the number of moves
        
        # 1. check if the board is valid
        if not self.is_valid(board):
            return -1
        
        # 2. find the number of moves to make the board a chessboard
        # 3. return the number of moves
        return self.find_moves(board)
        
        
    