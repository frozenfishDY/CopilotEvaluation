#https://leetcode.com/problems/guess-number-higher-or-lower-ii/
#We are playing the Guessing Game. The game will work as follows:
#I pick a number between 1 and n.
#You guess a number.
#If you guess the right number, you win the game.
#If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
#Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
#Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.


class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """       
        dp = [[0]*(n+1) for _ in range(n+1)]
        for lo in range(n,0,-1):
            for hi in range(lo+1,n+1):
                dp[lo][hi] = min(x + max(dp[lo][x-1],dp[x+1][hi]) for x in range(lo,hi))
        return dp[1][n]

        

    