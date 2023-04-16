#https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
#Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.
#A substring is a contiguous sequence of characters within a string.


class Solution(object):
    def queryString(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: bool
        """
        for i in range(1,n+1):
            if bin(i)[2:] not in s:
                return False
        return True
        

    