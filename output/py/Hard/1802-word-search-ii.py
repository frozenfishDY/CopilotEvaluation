#https://leetcode.com/problems/word-search-ii/
#Given an m x n board of characters and a list of strings words, return all words on the board.
#Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.


class Solution(object):
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        if not board:
            return []
        self.board = board
        self.m = len(board)
        self.n = len(board[0])
        self.res = []
        for word in words:
            if self.exist(word):
                self.res.append(word)
        return self.res
        
        
    