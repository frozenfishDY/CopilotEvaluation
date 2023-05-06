#https://leetcode.com/problems/word-search/
#Given an m x n grid of characters board and a string word, return true if word exists in the grid.
#The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m,n = len(board),len(board[0])
        for i in range(m):
            for j in range(n):
                if self.dfs(board,word,i,j,0):
                    return True
        return False
        

    