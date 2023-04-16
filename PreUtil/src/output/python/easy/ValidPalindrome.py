#https://leetcode.com/problems/valid-palindrome/
#A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
#Given a string s, return true if it is a palindrome, or false otherwise.


class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        res=""
        for i in range(len(s)):
            if s[i].isalnum():
                res=res+s[i].lower()
        return res==self.reverse(res)

    