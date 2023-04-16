#https://leetcode.com/problems/arranging-coins/
#You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
#Given the integer n, return the number of complete rows of the staircase you will build.


class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """      
        if n==0:
            return 0
        if n==1:
            return 1
        for i in range(1,n):
            if i*(i+1)/2<=n and (i+1)*(i+2)/2>n:
                return i
        
    