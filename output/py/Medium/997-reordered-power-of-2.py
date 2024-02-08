#https://leetcode.com/problems/reordered-power-of-2/
#You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
#Return true if and only if we can do this so that the resulting number is a power of two.


class Solution(object):
    def reorderedPowerOf2(self, n):
        """
        :type n: int
        :rtype: bool
        """                                                                                       
        return self.reorder(n, 0, 0, [False] * 10)

        

    