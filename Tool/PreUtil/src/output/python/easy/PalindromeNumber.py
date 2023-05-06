#https://leetcode.com/problems/palindrome-number/
#Given an integer x, return true if x is a palindrome, and false otherwise.

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """ 
        if x<0:
            return False
        else:
            str=str(x)
            for i in range(0,len(str)/2):
                if str[i]!=str[len(str)-1-i]:
                    return False
            return True

        
    