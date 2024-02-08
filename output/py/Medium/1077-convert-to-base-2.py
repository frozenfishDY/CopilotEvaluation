#https://leetcode.com/problems/convert-to-base-2/
#Given an integer n, return a binary string representing its representation in base -2.
#Note that the returned string should not have leading zeros unless the string is "0".


class Solution(object):
    def baseNeg2(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n==0:
            return "0"
        res=""
        while n!=0:
            res=str(n%2)+res
            n=-(n//2)
        return res
        

    