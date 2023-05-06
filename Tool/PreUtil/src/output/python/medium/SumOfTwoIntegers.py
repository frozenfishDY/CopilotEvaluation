#https://leetcode.com/problems/sum-of-two-integers/
#Given two integers a and b, return the sum of the two integers without using the operators + and -.


class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        while b:
            carry = a & b
            a = a ^ b
            b = carry << 1
        return a
        

    