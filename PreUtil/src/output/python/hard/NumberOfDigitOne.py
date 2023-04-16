#https://leetcode.com/problems/number-of-digit-one/
#Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.


class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 0:
            return 0
        res = 0
        i = 1
        while i <= n:
            a = n // i
            b = n % i
            res += (a + 8) // 10 * i + (a % 10 == 1) * (b + 1)
            i *= 10
        return res
        
        
    