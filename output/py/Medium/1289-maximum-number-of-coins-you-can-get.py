#https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
#There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:
#In each step, you will choose any 3 piles of coins (not necessarily consecutive).
#Of your choice, Alice will pick the pile with the maximum number of coins.
#You will pick the next pile with the maximum number of coins.
#Your friend Bob will pick the last pile.
#Repeat until there are no more piles of coins.
#Given an array of integers piles where piles[i] is the number of coins in the ith pile.
#Return the maximum number of coins that you can have.


class Solution(object):
    def maxCoins(self, piles):
        """
        :type piles: List[int]
        :rtype: int
        """
        piles.sort()
        return sum(piles[len(piles)//3::2])
        

    