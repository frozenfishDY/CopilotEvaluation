#https://leetcode.com/problems/zuma-game/
#You are playing a variation of the game Zuma.
#In this variation of Zuma, there is a single row of colored balls on a board, where each ball can be colored red 'R', yellow 'Y', blue 'B', green 'G', or white 'W'. You also have several colored balls in your hand.
#Your goal is to clear all of the balls from the board. On each turn:
#Pick any ball from your hand and insert it in between two balls in the row or on either end of the row.
#If there is a group of three or more consecutive balls of the same color, remove the group of balls from the board.
#If this removal causes more groups of three or more of the same color to form, then continue removing each group until there are none left.
#If there are no more balls on the board, then you win the game.
#Repeat this process until you either win or do not have any more balls in your hand.
#Given a string board, representing the row of balls on the board, and a string hand, representing the balls in your hand, return the minimum number of balls you have to insert to clear all the balls from the board. If you cannot clear all the balls from the board using the balls in your hand, return -1.


class Solution(object):
    def findMinStep(self, board, hand):
        """
        :type board: str
        :type hand: str
        :rtype: int
        """      
        if not board:
            return 0
        if not hand:
            return -1
        hand = list(hand)
        res = self.dfs(board,hand)
        return res if res != float('inf') else -1

        
        
    