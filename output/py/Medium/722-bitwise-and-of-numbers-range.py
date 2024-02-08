#https://leetcode.com/problems/bitwise-and-of-numbers-range/
#Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.


class Solution(object):
    def rangeBitwiseAnd(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        shift = 0
        while left < right:
            left >>= 1
            right >>= 1
            shift += 1
        return left << shift
        

    