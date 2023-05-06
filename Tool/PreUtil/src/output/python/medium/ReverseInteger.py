#https://leetcode.com/problems/reverse-integer/
#Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
#Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """     
        if x>=0:
            res = int(str(x)[::-1])
        else:
            res = -int(str(-x)[::-1])
        return res if res.bit_length() < 32 else 0
        

    