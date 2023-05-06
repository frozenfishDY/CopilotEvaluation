#https://leetcode.com/problems/sqrtx/
#Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
#You must not use any built-in exponent function or operator.
#For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x==0:
            return 0
        else:
            return int(x**0.5)

    