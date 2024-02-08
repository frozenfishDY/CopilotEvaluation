#https://leetcode.com/problems/binary-number-with-alternating-bits/
#Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.


class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """       
        n_bin=bin(n)[2:]
        for i in range(1,len(n_bin)):
            if n_bin[i]==n_bin[i-1]:
                return False
        return True
        

    