#https://leetcode.com/problems/nth-digit/
#Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].


class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = 0
        while n != 1:
            if n % 2 == 0:
                n /= 2
            elif n == 3 or n % 4 == 1:
                n -= 1
            else:
                n += 1
            res += 1
        return res
        

    